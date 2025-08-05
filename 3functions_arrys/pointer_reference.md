# 🧭 **Pointers and References**

---

## 🔹 Introduction to Pointers

### What is a Pointer?

A **pointer** is a variable that stores the **memory address** of another variable.

```cpp
int x = 10;
int *p = &x;  // p stores the address of x
```

### Why Use Pointers?

* Direct **memory access**
* **Dynamic memory allocation**
* **Efficient parameter passing** (avoid copying large data)
* Essential for **data structures** (linked lists, trees, graphs)

### Key Concepts:

* `&` → Address-of operator
* `*` → Dereference operator (access value at address)

### Example:

```cpp
int a = 5;
int *ptr = &a;

cout << "Address: " << ptr << endl;      // address of a
cout << "Value: " << *ptr << endl;       // value at that address (5)
```

---

## 🔹 Pointer Declaration and Initialization

### Syntax:

```cpp
int *ptr;      // pointer to int
double *dptr;  // pointer to double
```

### Null Pointer

Always initialize pointers, or set to `nullptr` if no address assigned yet:

```cpp
int *p = nullptr;  // safer than garbage address
```

---

## 🔹 Pointer and Variable Relationship

### How it works:

```cpp
int x = 42;
int *p = &x;

*p = 100;  // changes x
cout << x;  // 100
```

**Reasoning:** Dereferencing `p` (`*p`) gives access to `x`, so assigning to `*p` modifies `x`.

---

## 🔹 Pointers with Arrays

### Arrays and pointers are closely related.

```cpp
int arr[3] = {10, 20, 30};
int *p = arr;  // same as &arr[0]

cout << *p << endl;       // 10
cout << *(p + 1) << endl; // 20
```

**Reasoning:** Array name `arr` decays to pointer to first element. Pointer arithmetic lets us navigate through the array.

### Access using pointer notation:

```cpp
for (int i = 0; i < 3; i++) {
    cout << *(p + i) << " ";
}
```

---

## 🔹 Pointer Arithmetic

| Operation | Meaning                                     |
| --------- | ------------------------------------------- |
| `p++`     | Move to next element (depends on type size) |
| `p + n`   | Move `n` elements forward                   |
| `p - n`   | Move `n` elements backward                  |
| `p1 - p2` | Difference in number of elements            |

### Example:

```cpp
int arr[4] = {1, 2, 3, 4};
int *p = arr;

cout << *(p + 2);  // 3
```

---

## 🔹 Pointers and Functions

### Pass by Address

```cpp
void update(int *ptr) {
    *ptr = 50;
}

int x = 10;
update(&x);
cout << x;  // 50
```

**Reasoning:** Changes inside the function affect the original variable, because the function works on its address.

---

## 🔹 Dynamic Memory Allocation with `new` and `delete`

### Why?

* Allocate memory during runtime.
* Needed for flexible-size data (user-defined size arrays, linked lists, etc.)

### Syntax:

```cpp
int *p = new int;     // allocate single int
*p = 100;

int *arr = new int[5]; // array of 5 ints

delete p;             // deallocate memory
delete[] arr;         // delete dynamic array
```

**Important:** Always free memory with `delete` to avoid **memory leaks**.

---

## 🔹 Double Pointers (`Pointer to Pointer`)

### Use case:

* Managing multiple layers of indirection
* Dynamic 2D arrays
* Modifying pointer itself in a function

### Example:

```cpp
int x = 5;
int *p = &x;
int **pp = &p;

cout << **pp << endl;  // 5
```

---

## 🔹 Common Mistakes with Pointers

| Mistake                            | Explanation                      |
| ---------------------------------- | -------------------------------- |
| Dereferencing null/garbage pointer | Causes segmentation fault        |
| Not freeing memory                 | Leads to memory leak             |
| Dangling pointer                   | Pointer to deleted/freed memory  |
| Mixing up `*` and `&`              | Causes logical/compile-time bugs |

---

## 🔹 References in C++

### What is a Reference?

A **reference** is an **alias** (another name) for a variable.

```cpp
int x = 10;
int &ref = x;
```

Now `ref` and `x` are the same variable.

### Key Properties:

* Must be initialized at declaration
* Cannot be null
* Cannot change the reference to refer to another variable after initialization

---

## 🔹 Reference vs Pointer

| Feature           | Pointer                 | Reference     |
| ----------------- | ----------------------- | ------------- |
| Can be reassigned | ✅ Yes                   | ❌ No          |
| Can be null       | ✅ Yes (`nullptr`)       | ❌ No          |
| Syntax            | `*`, `&`, `->`          | just `&` once |
| Memory safe       | ❌ Risky (null/dangling) | ✅ Safer       |

---

## 🔹 Reference in Functions

### Pass by Reference

```cpp
void update(int &x) {
    x = 100;
}

int a = 10;
update(a);
cout << a;  // 100
```

**Reasoning:** Function receives **reference to original variable**, so changes reflect in the caller.

---

### Return by Reference

```cpp
int& getRef(int &x) {
    return x;
}

int a = 20;
getRef(a) = 50;
cout << a;  // 50
```

**Use case:** Modify caller’s variable from a function return.

---

## 🔹 Reference with Arrays

You **cannot bind a reference to an entire array** directly, but you can bind to individual elements or use references with functions.

```cpp
int arr[] = {1, 2, 3};
int &ref = arr[1];
ref = 100;

cout << arr[1];  // 100
```

---

## 🔹 Use Cases: When to Use Pointer vs Reference

| Scenario                                         | Use                 |
| ------------------------------------------------ | ------------------- |
| Modifying caller variable in a function          | Reference (cleaner) |
| Allocating dynamic memory                        | Pointer             |
| Multiple levels of indirection (e.g., 2D arrays) | Pointer             |
| Avoiding object copy for large data              | `const` reference   |
| When reference must be re-targeted               | Pointer             |

---

## 🔹 Practical Examples

### 1. Swap with Reference

```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### 2. Dynamic Array with Pointers

```cpp
int n;
cin >> n;
int *arr = new int[n];
for (int i = 0; i < n; i++) cin >> arr[i];
delete[] arr;
```

### 3. Pointer to Array Function Argument

```cpp
void print(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
```

### 4. Pointer to Struct

```cpp
struct Point {
    int x, y;
};

Point p = {10, 20};
Point *ptr = &p;
cout << ptr->x << " " << ptr->y;
```

---

## 🔚 Summary: Key Takeaways

### Pointers

* Store addresses, support dynamic memory
* Enable efficient data manipulation
* Require careful memory management

### References

* Aliases to existing variables
* Safer and more readable than pointers for many cases
* Useful for modifying function arguments

---
