# Big picture (when to use what)

* **References (`T&`, `const T&`)**
  Use when the parameter is **required** and **must not be null**. Cleaner call sites, safer defaults, great for in/out params and large read-only objects.

* **Pointers (`T*`, `const T*`)**
  Use when the parameter is **optional** (nullable), when you need **reseating** (change which object is referred to), when interoperating with C APIs, or when dealing with **arrays**/buffer interfaces (though `std::span` is usually better in modern C++).

---

# 1) Call-site ergonomics & intent

### Reference: required & non-null by design

```cpp
void scale(Vec& v, double s) { v.x *= s; v.y *= s; } // must have a Vec

Vec v{3,4};
scale(v, 2.0);           // ✅ call is clean
// scale(nullptr, 2.0);  // ❌ impossible
```

**Reasoning:** A reference must bind to a valid object at the call site; this encodes **non-null precondition** right in the type.

### Pointer: optional or nullable semantics

```cpp
void maybeScale(Vec* v, double s) {
    if (!v) return;      // optional: do nothing
    v->x *= s; v->y *= s;
}

Vec v{3,4};
maybeScale(&v, 2.0);     // ✅ modifies v
maybeScale(nullptr, 2.0); // ✅ allowed, no effect
```

**Reasoning:** The type communicates “**it might not be there**.” You must do null checks; that’s the trade-off for optionality.

---

# 2) Mutability & const-correctness

You can encode **read-only** vs **modifiable** precisely.

```cpp
void print(const std::string& s);  // no copy, read-only
void shout(std::string& s);        // may mutate s
void maybeFix(std::string* s);     // may be null, may mutate

// At call sites:
std::string name = "Ada";
print(name);        // cheap, safe
shout(name);        // modifies name
maybeFix(&name);    // caller signals mutability & optionality
```

**Reasoning:** `const&` is the standard way to avoid copying large objects without allowing mutation. For optional read-only, prefer `const std::string*`.

---

# 3) Overloading & API clarity

### Reference overloading (includes move semantics)

```cpp
void f(int&);            // lvalue
void f(const int&);      // const lvalue
void f(int&&);           // rvalue (temporary)

int x = 1;
f(x);        // calls int&
f(42);       // calls int&&
```

### Pointer overloading (nullability axis)

```cpp
void g(int*);            // non-const pointee
void g(const int*);      // const pointee

int x = 1;
g(&x);       // chooses based on constness of pointee
g(nullptr);  // valid call (must handle null)
```

**Reasoning:** References give you **value category** distinctions (`&` vs `&&`) which power move semantics; pointers give you **presence** distinctions (maybe null).

---

# 4) Arrays, buffers, and modern alternatives

### Pointer style (classic C/C++)

```cpp
void addOne(int* a, std::size_t n) {
    if (!a) return;           // must guard
    for (std::size_t i = 0; i < n; ++i) a[i] += 1;
}
```

### Reference to array (size captured in the type)

```cpp
template<std::size_t N>
void addOneArray(int (&a)[N]) {
    for (std::size_t i = 0; i < N; ++i) a[i] += 1;
}
```

### Modern C++20: `std::span`

```cpp
#include <span>

void addOne(std::span<int> a) {
    for (int& x : a) ++x;
}

// Calls:
int v[] = {1,2,3};
addOne(v);                      // decays to span
std::vector<int> w{4,5,6};
addOne(w);                      // implicit span
```

**Reasoning:**

* Raw pointer + size is error-prone (null? mismatched size?).
* Reference-to-array is safe but inflexible.
* **`std::span`** provides a non-owning, bounds-aware view—**best default** for “buffer parameters” in modern C++.

---

# 5) Reseating vs rebinding

* **Pointer** can be reseated (point to a different object).
* **Reference** cannot—once bound, it’s an alias for life.

```cpp
int a=1, b=2;
int* p = &a;
p = &b;           // ✅ reseat

int& r = a;
// r = b;         // ❌ assigns b's value to a, does NOT rebind r
```

**Reasoning:** If your function must **change which object** a parameter refers to, you need a **pointer to pointer** or a **reference to pointer**.

```cpp
void retarget(int*& refToPtr, int* newTarget) { refToPtr = newTarget; }
// or
void retarget2(int** p, int* newTarget) { *p = newTarget; }
```

---

# 6) Ownership & lifetime (modern guidance)

* Passing a **raw pointer** does **not** communicate ownership; it’s usually **non-owning**.
* If a function **takes ownership**, prefer smart pointers:

```cpp
void take(std::unique_ptr<Foo> f);   // transfers ownership (by value)
void observe(const Foo* f);          // non-owning, maybe null
void use(Foo& f);                    // required, non-null, non-owning
```

**Reasoning:** With smart pointers, ownership rules are explicit and RAII handles cleanup; references/pointers then clearly signal non-owning use.

---

# 7) Optional parameters & out-params

### Optional input—pointer makes sense

```cpp
void draw(Shape* s) {
    if (!s) return;  // optional Shape
    s->render();
}
```

### Output values—prefer return values (and structs), not out-pointers

```cpp
// Prefer:
std::optional<Point> tryFind();

// If you must:
bool tryFind(Point* out) {
    if (!out) return false;           // defensive
    *out = {/*...*/};
    return true;
}
```

**Reasoning:** Returning values is clearer and exception-safe. Use pointer out-params only for legacy/C interop or when unavoidable.

---

# 8) Under the hood (how they’re passed)

Both references and pointers are typically compiled down to **addresses** in registers/stack slots. The **semantic** difference is type-level:

* Reference: the callee treats it as **must be valid**.
* Pointer: callee must **assume it could be null** and check.

*(You can’t legally bind a reference to null; forcing it via casts leads to UB.)*

---

# 9) Contrasting code: same task, different intent

## A) Modify in place: reference (clean) vs pointer (explicit)

```cpp
struct Settings { int volume; bool muted; };

// Reference version (required, non-null)
void normalize(Settings& s) {
    if (s.volume < 0) s.volume = 0;
    if (s.volume > 100) s.volume = 100;
}

// Pointer version (optional)
void maybeNormalize(Settings* s) {
    if (!s) return;
    if (s->volume < 0) s->volume = 0;
    if (s->volume > 100) s->volume = 100;
}

int main() {
    Settings a{120,false};
    normalize(a);              // ✅ must pass a valid Settings

    Settings* p = nullptr;
    maybeNormalize(p);         // ✅ optional, no-op
}
```

**Reasoning:** The pair communicates different **contracts** without comments.

---

## B) Arrays/buffers: pointer + size vs span vs reference-to-array

```cpp
// 1) Pointer + size
size_t countPositives(const int* a, size_t n) {
    if (!a) return 0;
    size_t c = 0;
    for (size_t i = 0; i < n; ++i) if (a[i] > 0) ++c;
    return c;
}

// 2) span (modern)
#include <span>
size_t countPositives(std::span<const int> a) {
    size_t c = 0;
    for (int x : a) if (x > 0) ++c;
    return c;
}

// 3) reference to array (compile-time size)
template<size_t N>
size_t countPositives(const int (&a)[N]) {
    size_t c = 0;
    for (int x : a) if (x > 0) ++c;
    return c;
}
```

**Reasoning:** Prefer `std::span` unless you truly need compile-time size.

---

## C) Polymorphism: reference vs pointer

```cpp
struct Shape { virtual ~Shape() = default; virtual void draw() const = 0; };
struct Circle : Shape { void draw() const override { /*...*/ } };

// Required draw:
void paint(Shape& s) { s.draw(); }

// Optional draw:
void maybePaint(Shape* s) { if (s) s->draw(); }
```

**Reasoning:** Both support virtual dispatch; **choose based on nullability**.

---

## D) Move-only types: `T&&` advantage over pointers

```cpp
void sink(std::unique_ptr<Foo> p);  // takes ownership
void sinkRef(std::unique_ptr<Foo>&& p); // also fine, often forwarding

auto p = std::make_unique<Foo>();
sink(std::move(p));                 // clear ownership transfer
```

**Reasoning:** Move semantics are expressed through **references**, not pointers.

---

# 10) Common pitfalls & how to avoid

* **Dangling references/pointers:** Don’t return references to locals; don’t store pointers to temporaries.
* **Accidental copies:** For large types, use `const T&` in parameters.
* **Overusing out-pointers:** Prefer return values or structured returns.
* **Nullable references:** Not a thing—don’t fake it; use pointers or `std::optional<std::reference_wrapper<T>>` if you need an optional non-owning reference.

---

# Practical decision guide

* **Must be present and non-null?** → `T&` / `const T&`
* **Might be absent?** → `T*` / `const T*` (or better: `std::optional<T>` if you can copy/move)
* **Large read-only input?** → `const T&`
* **Takes ownership?** → `std::unique_ptr<T>` by value (or `std::shared_ptr<T>` if shared)
* **Buffer parameter?** → `std::span<T>` / `std::span<const T>`
* **Needs to reseat which object is referenced?** → pointer to pointer (`T**`) or reference to pointer (`T*&`)

---
