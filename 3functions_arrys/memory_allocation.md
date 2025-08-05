# 🧠 C++ Session: **Static vs. Dynamic Memory Allocation**

---

## 🔰 Introduction to Memory Allocation

In C++, memory for variables can be allocated in **two primary ways**:

| Type                          | Description                                                         |
| ----------------------------- | ------------------------------------------------------------------- |
| **Static Memory Allocation**  | Memory size is fixed at compile time and is allocated on stack      |
| **Dynamic Memory Allocation** | Memory size is known and allocated at runtime using heap            |

Understanding when and how to use each type is crucial for writing efficient and scalable programs.

---

## 🔷 Static Memory Allocation

### What is Static Allocation?

* **Static memory allocation** means that the **size and layout of memory** is determined at **compile time**.
* But the **actual allocation (i.e., memory being set aside in RAM)** happens when the **program runs** — i.e., at **runtime**.

### Characteristics:

* Uses **Stack memory**
* Fixed size
* Automatically managed (no `delete`)
* Fast access

### Example:

```cpp
int x = 10;          // statically allocated
int arr[5];          // statically sized array
```

### Scope:

Static memory is automatically **freed** when the variable **goes out of scope**.

---

## 🧠 So what's really happening?

### 🔹 1. **At Compile Time:**

* The **compiler decides** how much memory is needed (for global/static variables, and for each stack frame).
* The memory **addresses** are **determined relative to segments** (like `.data`, `.bss`, `.stack`).
* The compiled binary includes information about how much memory is needed and where.

### 🔹 2. **At Runtime:**

* When the program **starts**, the OS allocates memory for:

  * **Code**
  * **Global/static variables** (from `.data`/`.bss` segment)
  * **Stack frame** for local variables
* The memory for static variables is **automatically available when needed**, but it comes from the OS **at runtime**.

---

## 📦 Analogy

Imagine:

* **Compile time**: You submit a blueprint to build a house (room sizes and layouts are fixed)
* **Runtime**: The workers actually **build the house** using the blueprint

So the compiler **designs** the memory layout, but the OS **allocates** it at program **execution time**.

---

## ✅ Conclusion:

| Aspect                            | Static Memory Allocation   |
| --------------------------------- | -------------------------- |
| Size and layout decided           | ✅ Compile time             |
| Actual memory given by OS         | ✅ Runtime                  |
| Can size change during execution? | ❌ No                       |
| Is it automatically managed?      | ✅ Yes (no manual `delete`) |

---

### 📌 Pros:

* Fast access (stack is faster than heap)
* No manual memory management

### ❗ Cons:

* Wastes memory if overestimated
* Risk of stack overflow if large arrays are allocated
* Inflexible (can’t change size at runtime)

---

### 🧠 When to Use:

* When size is **fixed or small**
* For local variables inside functions
* For known compile-time constants

---

## 🔷 Dynamic Memory Allocation

### What is Dynamic Allocation?

Dynamic allocation lets you request memory from the **heap at runtime** using operators like `new` and `delete`.

This is useful when:

* You don't know how much memory you need at compile time
* You want to manage memory lifetime manually
* You're building data structures like linked lists, trees, graphs, etc.

---

### Syntax:

```cpp
int *ptr = new int;         // single int
int *arr = new int[5];      // array of 5 ints
```

### Releasing Memory:

```cpp
delete ptr;       // for single variable
delete[] arr;     // for array
```

### Example:

```cpp
int n;
cin >> n;
int *arr = new int[n];  // dynamic size
for (int i = 0; i < n; i++) cin >> arr[i];

delete[] arr;
```

---

### 📌 Pros:

* Flexible memory allocation
* Good for large/variable-size data
* Memory persists beyond function scope (if pointer stored globally)

### ❗ Cons:

* Requires manual cleanup (`delete`)
* Risk of memory leaks and dangling pointers
* Slower than stack allocation

---

### 🧠 When to Use:

* When size is **unknown at compile-time**
* For data structures that grow/shrink dynamically
* When you need memory to persist beyond function calls

---

## 🧬 Static vs Dynamic: Comparison Table

| Feature          | Static Allocation       | Dynamic Allocation             |
| ---------------- | ----------------------- | ------------------------------ |
| Allocation time  | Compile-time            | Runtime                        |
| Memory location  | Stack                   | Heap                           |
| Size flexibility | Fixed                   | Flexible                       |
| Lifetime         | Automatic (scope-based) | Manual (programmer-controlled) |
| Syntax           | `int x;`                | `int *x = new int;`            |
| Memory cleanup   | Automatic               | Must use `delete` manually     |
| Risk             | Stack overflow          | Memory leak, dangling pointer  |

---

## 🧪 Practical Examples

---

### 1. Static Array Example

```cpp
void printStatic() {
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
        cout << arr[i] << " ";
}
```

* Memory for `arr` is allocated and deallocated automatically.

---

### 2. Dynamic Array Example

```cpp
void printDynamic(int n) {
    int *arr = new int[n];  // user-defined size
    for (int i = 0; i < n; i++)
        arr[i] = i * i;
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;  // cleanup
}
```

* Ideal for runtime-sized arrays like in competitive programming or matrix input.

---

### 3. Dynamic Memory for Class Objects

```cpp
class Student {
public:
    string name;
    Student(string n) : name(n) {}
    void greet() { cout << "Hello " << name << endl; }
};

Student *s = new Student("Alice");
s->greet();     // Output: Hello Alice
delete s;
```

* Dynamic memory for object creation when lifetime control is needed.

---

## 💣 Common Pitfalls

### ❌ Memory Leak

```cpp
int *ptr = new int;
// forget to delete
```

* Memory stays allocated forever → **leak**

---

### ❌ Dangling Pointer

```cpp
int *ptr = new int(5);
delete ptr;
cout << *ptr;  // undefined behavior
```

* Accessing memory after deletion → **dangerous**

---

### ❌ Double Delete

```cpp
int *ptr = new int;
delete ptr;
delete ptr;  // crash
```

---

## 🧼 Best Practices for Dynamic Memory

1. Always `delete` what you `new`
2. Use `nullptr` after deletion to avoid dangling pointers:

   ```cpp
   delete ptr;
   ptr = nullptr;
   ```
3. Prefer **smart pointers** (from `<memory>`) like `unique_ptr` and `shared_ptr` for modern C++

---

## 🛠️ Advanced: Smart Pointers (Preview)

Modern C++ discourages raw `new`/`delete`. Instead, use **smart pointers** which automatically manage memory.

```cpp
#include <memory>

auto p = std::make_unique<int>(10);
cout << *p;
```

* No need to call `delete`
* Prevents memory leaks
* Safer in exception handling

---

## 🧪 Sample Project Idea: Student Database

* Ask user how many students → allocate dynamically
* Store student names and scores
* Print average score
* Delete memory after use

---

## ✅ Summary

| Concept            | Use Case                                         |
| ------------------ | ------------------------------------------------ |
| Static allocation  | Known size, short lifetime, simple logic         |
| Dynamic allocation | Unknown size, long lifetime, advanced structures |
| Delete memory      | Always for `new` allocations                     |
| Smart pointers     | Safer alternative to raw pointers                |

---
