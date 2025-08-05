# 🧑‍🏫 C++ **Functions & Arrays**

### 🎯 Learning Goals:

* Understand and apply functions for modular coding
* Master arrays for storing and processing collections of data
* Learn memory, scope, and best practices

---

## 📚 Session Breakdown

| Topic                                           |
| ----------------------------------------------- |
| Introduction to Functions                       |
| Function Types, Parameters, Return Values       |
| Function Overloading, Scope, and Storage        |
| Arrays: Declaration, Access, and Initialization |
| Array Traversal, Input/Output, Basic Programs   |
| Arrays as Function Arguments                    |
| Multidimensional Arrays                         |
| Practical Programs with Arrays + Functions      |
| Exercises, Q\&A, Summary & Best Practices       |

---

## 🕐**Introduction to Functions**

### ✅ Concepts:

* What is a function?
* Why are functions important?
* Built-in vs. user-defined functions

### 🧠 Reasoning:

* Functions help **break complex problems into small tasks**, **avoid repetition**, and **improve code readability** and **reusability**.
* Functions promote moduler programming.

### 🧾 Example:

```cpp
void greet() {
    cout << "Hello, User!" << endl;
}

int main() {
    greet();  // function call
    return 0;
}
```

---

## 🕐 **Function Types, Parameters & Return Values**

### ✅ Concepts:

* Function declaration & definition
* Parameters (formal) and arguments (actual)
* Return types (`void`, `int`, etc.)
* Default parameters: Should always follow non-default parameters (only if any).

### 🧠 Reasoning:

Functions allow us to reuse logic with different inputs and return values.

### 🧾 Examples:

```cpp
int add(int a, int b) {
    return a + b;
}

void display(string name = "Guest") {
    cout << "Hello, " << name << endl;
}

void test(string name = "Guest", int x) { // this is not allowed
    cout << "Hello, " << name << endl;
}
```

---

## 🕐 **Overloading, Scope, Storage Classes**

### ✅ Concepts:

* Function overloading
* Scope of variables (`local`, `global`)
* `static` variables inside functions

### 🧠 Reasoning:

* Overloading allows the same function name for different different signatures/data types.
* Static scope preserves values across calls.

### 🧾 Example:

```cpp
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }

void counter() {
    static int count = 0;
    cout << ++count << endl;
}
```

Certainly! Let's dive into the core difference between **pass by value** and **pass by reference** in C++, along with **clear examples**, **behavior**, and **reasoning**.

---

# 🧠 Understanding: Pass by Value vs Pass by Reference in C++

---

## 🧾 1. What Is **Pass by Value**?

### ✅ Definition:

When you **pass a variable by value**, a **copy** of the original variable is made and sent to the function.
Changes made inside the function **do not affect** the original variable.

### 📌 Syntax:

```cpp
void func(int x) {
    x = 10;  // Only local copy is modified
}
```

### 🧪 Example:

```cpp
#include <iostream>
using namespace std;

void modify(int x) {
    x = 100;
}

int main() {
    int a = 5;
    modify(a);
    cout << "a = " << a << endl;  // Output: a = 5
}
```

### 🧠 Reasoning:

Use **pass by value** when:

* You don't want the original data to be changed.
* You are working with small-sized data (e.g., `int`, `char`) for efficiency.

---

## 🧾 2. What Is **Pass by Reference**?

### ✅ Definition:

When you **pass by reference**, the function gets a **direct reference (alias)** to the original variable.
Changes made inside the function **affect the original** variable.

### 📌 Syntax:

```cpp
void func(int &x) {
    x = 10;  // Directly modifies the caller's variable
}
```

### 🧪 Example:

```cpp
#include <iostream>
using namespace std;

void modify(int &x) {
    x = 100;
}

int main() {
    int a = 5;
    modify(a);
    cout << "a = " << a << endl;  // Output: a = 100
}
```

### 🧠 Reasoning:

Use **pass by reference** when:

* You want the function to **modify the original variable**.
* You are passing **large objects or arrays** to avoid copying.
* You want **efficient memory usage**.

---

## ✅ Comparison Table

| Feature                 | Pass by Value          | Pass by Reference             |
| ----------------------- | ---------------------- | ----------------------------- |
| What is passed?         | A copy of the variable | The original variable (alias) |
| Can it modify original? | ❌ No                   | ✅ Yes                         |
| Memory efficient?       | ❌ No (for large data)  | ✅ Yes                         |
| Safe from side-effects? | ✅ Yes                  | ❌ No                          |
| Syntax                  | `func(int x)`          | `func(int &x)`                |

---

## 🔎 Bonus: `const` Reference

You can prevent modification using a **const reference**:

```cpp
void show(const int &x) {
    cout << "Value: " << x << endl;
    // x = 10; ❌ Error: cannot modify const reference
}
```

Used when:

* You want to avoid copying **large data** like strings or structs.
* But still want to **protect from accidental modification**.

---

## 🧪 Example: Swap Two Numbers

### ❌ Using Pass by Value (Won’t Work)

```cpp
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### ✅ Using Pass by Reference

```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

---

## 🧠 Summary

| Use Case                                  | Choose                             |
| ----------------------------------------- | ---------------------------------- |
| Read-only, safe call                      | Pass by value or `const` reference |
| You need to modify original               | Pass by reference                  |
| Large data types (e.g., strings, structs) | `const` reference for efficiency   |
| Small types (int, char)                   | Pass by value                      |


---

## 🕐 **Arrays — Declaration, Initialization, Access**

### ✅ Concepts:

* What is an array?
* Declaration: `int arr[5];`
* Initialization: `int arr[] = {1, 2, 3};`
* Indexing and 0-based access

### 🧠 Reasoning:

Arrays store multiple homogeneous values in a **single contiguous block of memory** — useful for grouped data processing (e.g., scores, temperatures).

### 🧾 Example:

```cpp
int scores[3] = {90, 85, 70};
cout << scores[1];  // 85
```

---

## 🕐 **Array Traversal & Basic Programs**

### ✅ Concepts:

* Access using loops
* Input from user
* Sum, average, min, max

### 🧠 Reasoning:

Looping allows scalable operations over data without hardcoding every index.

### 🧾 Example:

```cpp
int arr[5], sum = 0;
for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum += arr[i];
}
cout << "Sum = " << sum;
```

---

## 🕐 **Passing Arrays to Functions**

### ✅ Concepts:

* Arrays as arguments
* Effects of reference passing
* Constant arrays

### 🧠 Reasoning:

Arrays are passed by reference — function can **modify original data**.

### 🧾 Example:

```cpp
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
```

---

## 🕐 **Multidimensional Arrays**

### ✅ Concepts:

* 2D Arrays: `int matrix[2][3];`
* Initialization, access
* Use in matrix operations

### 🧠 Reasoning:

2D arrays are perfect for **tables**, **matrices**, **grids**, etc.

### 🧾 Example:

```cpp
int mat[2][2] = {{1, 2}, {3, 4}};
cout << mat[1][0];  // 3
```

---

## 🕐 **Some Programs Combining Arrays & Functions**

### ✅ Projects:

1. Find average score of students
2. Reverse an array using a function
3. Sum of diagonal elements in a matrix
4. Count even and odd numbers
5. Linear search using function

### 🧾 Sample: Reverse Array

```cpp
void reverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--)
        cout << arr[i] << " ";
}
```

---

## 🕐 **Exercises, Q\&A, Best Practices**

### ✅ Exercises:

* Write a function to find the maximum in an array.
* Create a matrix multiplication program.
* Write a function to sort an array.

### ✅ Best Practices:

* Use meaningful function/array names.
* Keep function size small.
* Avoid magic numbers — use constants.
* Validate array indices before access.
* Use `const` for read-only arrays.

---

## ✅ Summary

| Topic          | Key Takeaway                       |
| -------------- | ---------------------------------- |
| Functions      | Code reuse, modularity             |
| Parameters     | Customize behavior                 |
| Arrays         | Efficient data storage             |
| 2D Arrays      | Matrix-like data                   |
| Combining both | Cleaner logic, reusable algorithms |

---
