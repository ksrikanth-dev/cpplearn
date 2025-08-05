# 🧠 Understanding C++ Memory layout

Every C++ program's memory is divided into **segments**, and where a variable resides depends on **how it is declared**.

---

## 🎯 Learning Objectives:

By the end of this session, you will:

* Understand the structure of a C++ program's memory.
* Know where variables are stored and how memory is allocated.
* Differentiate stack, heap, static, and code segments.
* Recognize memory issues like stack overflow, heap corruption, dangling pointers, etc.
* Be able to debug memory-related issues more effectively.
---

## 📚 Session Overview

| Module | Topic                               |
| ------ | ----------------------------------- |
| 1      | Introduction to Memory Layout       |
| 2      | Code Segment                        |
| 3      | Data Segment (Global & Static)      |
| 4      | Stack Memory                        |
| 5      | Heap Memory                         |
| 6      | Function Call Memory Walkthrough    |
| 7      | Memory Leaks, Dangling Pointers     |
| 8      | Visual Diagrams & Practice Examples |

---

## 🔹 1. Introduction to Memory Layout

Every C++ program in memory is typically divided into **five segments**:

```
+----------------------+
| Command-Line Args    |
| Environment Variables|
+----------------------+
| Stack Segment        | ← grows down
+----------------------+
| Heap Segment         | ← grows up
+----------------------+
| BSS Segment (.bss)   | (uninitialized global/static)
+----------------------+
| Data Segment (.data) | (initialized global/static)
+----------------------+
| Code/Text Segment    |
+----------------------+
```

---

### 🔍 Reasoning:

* Organized structure ensures **efficiency**, **safety**, and **separation of concerns**.
* Knowing this layout helps you understand **where variables live**, their **lifetime**, and their **visibility**.

---

## 🔸 2. Code Segment (Text Segment)

### ✅ Characteristics:

* Stores compiled machine instructions (your functions and logic).
* Usually **read-only** to prevent accidental overwriting.
* Shared among multiple processes (e.g., standard library code).

### 🧾 Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

* The `add()` function's instructions are stored in the **code segment**.

---

## 🔸 3. Data Segment

### ✅ Characteristics:

* Stores **global** and **static** variables.
* Divided into:

  * `.data` → for **initialized** data
  * `.bss` → for **uninitialized** data (global/static)

### 🧾 Example:

```cpp
int globalVar = 10;       // .data
static int count;         // .bss (defaults to 0)
int globalVar1;           // .bss (defaults to 0)
```

### 📌 Reasoning:

* This data is allocated when the program **starts**, and persists until **program ends**.

---

## 🔸 4. Stack Segment

### ✅ Characteristics:

* Stores:

  * Local variables
  * Function parameters
  * Return addresses
* Follows **LIFO** (Last In First Out)
* Automatically cleaned up

### 🧾 Example:

```cpp
void func() {
    int x = 5;      // x is stored on the stack
}
```

### ⚠️ Stack Overflow Example:

```cpp
void infiniteRecursion() {
    infiniteRecursion();
}
```

* Recursion without base case will **overflow the stack** (crash).

---

## 🔸 5. Heap Segment

### ✅ Characteristics:

* Dynamically allocated memory
* Must be managed manually with `new`/`delete` or smart pointers
* Grows **upwards**

### 🧾 Example:

```cpp
int* ptr = new int(10);
delete ptr;  // free memory
```

### ⚠️ Heap Memory Issues:

* **Memory leaks**: `new` without `delete`
* **Dangling pointers**: `delete` then access

---

## 🔸 6. Function Call Memory Walkthrough

Let's step through this code:

```cpp
int global = 5;

void printSquare(int x) {
    int result = x * x;
    cout << result;
}

int main() {
    int a = 10;
    printSquare(a);
}
```

### 🔍 Memory Flow:

1. `global` → data segment
2. `main()` local `a` → stack
3. `printSquare()`:

   * parameter `x` → stack
   * local `result` → stack

When `printSquare()` returns:

* Its **stack frame is popped**.

---

## 🔸 7. Common Memory Errors and Debugging

### 🔥 Dangling Pointer

```cpp
int* p;
{
    int x = 5;
    p = &x;
}
// x no longer exists here — `p` is dangling!
```

### 🔥 Memory Leak

```cpp
int* arr = new int[100];
// forget delete → memory leak
```

### 🛠️ Tools to Help:

* `valgrind` (Linux)
* Visual Studio Diagnostic Tools
* Static analyzers

---

## 🔸 8. Visual Diagrams

Here’s a visual for understanding stack vs heap:

```
Memory Layout:
+--------------------------+
| Stack (grows downward)   |
| - local variables        |
| - function parameters    |
+--------------------------+
| Heap (grows upward)      |
| - new allocations        |
+--------------------------+
| BSS (.bss)               |
| - static int x;          |
+--------------------------+
| Data (.data)             |
| - int global = 5;        |
+--------------------------+
| Code (.text)             |
| - main(), functions      |
+--------------------------+
```

---

## ✅ Practice Problems

1. **Identify Memory Segments**
   Mark where each variable lives:

   ```cpp
   int g = 10;
   void foo() {
       static int s = 5;
       int l = 2;
   }
   ```

2. **Write a program that dynamically allocates an array, fills it with values, prints it, and safely deallocates it.**

3. **Simulate stack overflow with deep recursion.**

---

## 🧠 Summary: Key Takeaways

| Segment | Stores                 | Lifetime       | Managed By              |
| ------- | ---------------------- | -------------- | ----------------------- |
| Code    | Instructions           | Entire program | OS                      |
| Data    | Global/static (init)   | Entire program | OS                      |
| BSS     | Global/static (uninit) | Entire program | OS                      |
| Stack   | Local vars, params     | Function scope | Auto                    |
| Heap    | Dynamic memory         | Until deleted  | Manual / Smart Pointers |

---

## 🔷 The 5 Primary Segments:

| Segment       | Stores                               | Lifetime              | Accessed via        |Managed By   |
| ------------- | ------------------------------------ | --------------------- | ------------------- |----------   |
| **Text/Code** | Function instructions                | Entire program        | Implicit            |OS           |
| **Data**      | Global/static **initialized** vars   | Entire program        | Direct/global scope |OS           |
| **BSS**       | Global/static **uninitialized** vars | Entire program        | Direct/global scope |OS           |
| **Heap**      | Dynamically allocated memory (`new`) | Manual until `delete` | Pointers            |auto         |
| **Stack**     | Function-local variables, params     | Per function call     | Local scope         |Manual       |

---

## ✅ Detailed Reasoning: How Variables Get Placed

### 1. **Global/Static Initialized Variables → Data Segment**

Declared outside any function or with `static`, and initialized.

```cpp
int global_init = 100;           // Data segment
static int static_init = 50;     // Data segment (even inside functions)
```

---

### 2. **Global/Static Uninitialized Variables → BSS Segment**

Same as above but **uninitialized** (or initialized to zero).

```cpp
int global_uninit;          // BSS segment
static int static_uninit;   // BSS segment
```

---

### 3. **Local (Non-static) Variables → Stack**

Declared inside functions without `static`.

```cpp
void func() {
    int local = 10;  // Stack
}
```

---

### 4. **Static Local Variables → Data/BSS**

Inside functions with `static`.

```cpp
void func() {
    static int counter = 0; // Data segment (if initialized), BSS otherwise
}
```

---

### 5. **Dynamically Allocated Variables → Heap**

Anything created with `new` or `malloc`.

```cpp
int *heap_var = new int(100);   // Heap
```

---

### 6. **String Literals → Read-Only Data Segment**

String constants live in a read-only memory block (part of text or rodata segment).

```cpp
const char *msg = "Hello";  // Pointer on stack, string literal in read-only memory
```

---

## 🔍 Practical Methods to Check Memory Segment of Variables

### ✅ Method 1: Use the `&` Operator to Print Addresses

```cpp
#include <iostream>
using namespace std;

int global_init = 100;
int global_uninit;

void check_segments() {
    static int static_init = 10;
    static int static_uninit;

    int local_var = 5;
    int *heap_var = new int(20);

    const char *str = "Hello World";

    cout << "Global (init):     " << &global_init << endl;
    cout << "Global (uninit):   " << &global_uninit << endl;
    cout << "Static (init):     " << &static_init << endl;
    cout << "Static (uninit):   " << &static_uninit << endl;
    cout << "Local:             " << &local_var << endl;
    cout << "Heap:              " << heap_var << endl;
    cout << "String literal:    " << (void*)str << endl;

    delete heap_var;
}

int main() {
    check_segments();
    return 0;
}
```

### 🧠 Reasoning Behind Output:

When you run the above code:

* You’ll see addresses of variables.
* Addresses from the **same segment are close together**.
* For example:

  * Stack variables (local) will have similar addresses (and vary between runs).
  * Heap will usually have a different region (often far apart).
  * Data/BSS/Code will have static addresses (same each run).

---

### ✅ Method 2: Use OS/Compiler Tools (Platform-Specific)

#### 🛠 On Linux: Use `pmap`, `gdb`, or `/proc/self/maps`

1. **Run your compiled program:**

   ```sh
   ./a.out
   ```

2. **Open another terminal:**

   ```sh
   pmap <pid>
   ```

3. Or examine:

   ```sh
   cat /proc/<pid>/maps
   ```

You will see memory regions like:

```
00400000-0040b000 r-xp 00000000 08:01 1234567 /home/user/a.out    # code/text
0060b000-0060c000 rw-p 0000b000 08:01 1234567 /home/user/a.out    # data
00a00000-00a21000 rw-p 00000000 00:00 0                            # heap
7ffcd5dfd000-7ffcd5e1e000 rw-p 00000000 00:00 0                    # stack
```

#### 🛠 On Windows:

Use tools like:

* **Visual Studio Debugger** → View memory & address
* **Process Explorer** by Sysinternals
* **Debugger Output Window**

---

### ✅ Method 3: Use `nm` to inspect binary symbols (Linux)

```sh
nm ./a.out | grep global
```

Symbols starting with:

* `B` → BSS
* `D` → Data
* `T` → Text

---

### ✅ Method 4: Visual Tools (Advanced)

* **Valgrind’s `massif`** → memory profile visualization
* **gdb + `info locals`**, `x` → inspect address during function calls
* **AddressSanitizer** → detect invalid memory access

---

## 📌 Summary Table (with Code Examples)

| Declaration          | Example                      | Segment     |
| -------------------- | ---------------------------- | ----------- |
| Global initialized   | `int a = 10;`                | Data        |
| Global uninitialized | `int b;`                     | BSS         |
| Local variable       | `int x = 5;` inside function | Stack       |
| Static variable      | `static int s = 2;`          | Data / BSS  |
| Dynamic allocation   | `new int(10);`               | Heap        |
| String literal       | `"Hello"`                    | Read-only   |
| Function code        | `void foo() {}`              | Text / Code |


Memory Layout:
+--------------------------+
| Stack (grows downward)   |
| - local variables        |
| - function parameters    |
+--------------------------+
| Heap (grows upward)      |
| - new allocations        |
+--------------------------+
| BSS (.bss)               |
| - static int x;          |
+--------------------------+
| Data (.data)             |
| - int global = 5;        |
+--------------------------+
| Code (.text)             |
| - main(), functions      |
+--------------------------+


---

## 🧪 Exercises

1. **Write a program with variables of each type** and use `cout << &var` to print addresses.
2. **Run it multiple times** and compare stack, heap, and data segment addresses.
3. **Write a function that dynamically allocates memory, stores values, and prints addresses**.

---
