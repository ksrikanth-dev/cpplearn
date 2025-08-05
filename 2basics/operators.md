# 🧑‍🏫 **Operators in C++**

### 🎯 Goal: Understand all types of C++ operators with practical examples and reasoning.

---

## 🗂️ Session Structure

| Topic                                                   |
| ------------------------------------------------------- |
| Introduction to Operators                               |
| Arithmetic Operators                                    |
| Relational (Comparison) Operators                       |
| Logical Operators                                       |
| Assignment Operators                                    |
| Increment/Decrement & Ternary Operator                  |
| Bitwise Operators                                       |
| Operator Precedence, Associativity & Practice Exercises |

---

## 🔹 1. What Are Operators?

### 🧠 Concept:

Operators are **symbols or keywords** that tell the compiler to perform specific operations on variables or values.

### 💡 Why Important?

* Everything in programming revolves around manipulating data.
* Operators let us **compute**, **compare**, **decide**, and **manipulate bits**.

---

## 🔹 2. Arithmetic Operators
Binary operators

| Operator | Description         | Example |
| -------- | ------------------- | ------- |
| `+`      | Addition            | `a + b` |
| `-`      | Subtraction         | `a - b` |
| `*`      | Multiplication      | `a * b` |
| `/`      | Division            | `a / b` |
| `%`      | Modulus (remainder) | `a % b` |

Note: `%` can be used only with Integers

### 🧪 Example:

```cpp
int a = 10, b = 3;
cout << a + b << endl;  // 13
cout << a % b << endl;  // 1
```

### 🧠 Reasoning:

* Used for calculations, billing systems, measurements, etc.
* `%` is useful in problems like even/odd, time formatting, hash functions.

---

## 🔹 3. Relational Operators

| Operator | Description              | Example  | Result     |
| -------- | ------------------------ | -------- | ---------- |
| `==`     | Equal to                 | `a == b` | true/false |
| `!=`     | Not equal to             | `a != b` | true/false |
| `>`      | Greater than             | `a > b`  | true/false |
| `<`      | Less than                | `a < b`  | true/false |
| `>=`     | Greater than or equal to | `a >= b` | true/false |
| `<=`     | Less than or equal to    | `a <= b` | true/false |

### 🧪 Example:

```cpp
int age = 18;
cout << (age >= 18) << endl;  // 1 (true)
```

NZ - true
Z - false
### 🧠 Reasoning:

* Forms the **basis of all decision-making** in a program.
* Used in `if`, `while`, `for`, validations, etc.

---

## 🔹 4. Logical Operators

| Operator | Description | Syntax            |
| -------- | ----------- | ----------------- |
| `&&`     | Logical AND | `a > 5 && b < 10` |
| `||`     | Logical OR  | `a > 5 || b < 10` |
| `!`      | Logical NOT | `!isTrue`         |


### 🧪 Example:

```cpp
bool isStudent = true;
bool hasID = true;

if (isStudent && hasID) {
    cout << "Entry allowed" << endl;
}
```

### 🧠 Reasoning:

* Combines multiple conditions.
* Logical expressions power decision trees, permission systems, etc.

---

## 🔹 5. Assignment Operators

| Operator | Description         | Equivalent             |
| -------- | ------------------- | ---------------------- |
| `=`      | Simple assign       | `a = 5`                |
| `+=`     | Add and assign      | `a += 2` → `a = a + 2` |
| `-=`     | Subtract and assign | `a -= 3`               |
| `*=`     | Multiply and assign | `a *= 4`               |
| `/=`     | Divide and assign   | `a /= 2`               |
| `%=`     | Modulus and assign  | `a %= 2`               |

### 🧪 Example:

```cpp
int a = 10;
a += 5;  // a = 15
```

### 🧠 Reasoning:

* **Shorter syntax** → **cleaner code**.
* Frequently used in loops, counters, accumulators.

---

## 🔹 6. Increment & Decrement Operators
Unary
| Example      |
| -------- | ----------- | ------------ |
| `++`     | Increment   | `a++`, `++a` |
| `--`     | Decrement   | `a--`, `--a` |


### ⚠️ Pre vs Post:

```cpp
int a = 5;
cout << a++ << endl; // prints 5, then a becomes 6
cout << ++a << endl; // a becomes 7, then prints 7
```

### 🧠 Reasoning:

* Useful in **loops, iterations**, and **manipulating counters**.

---

## 🔹 7. Ternary Operator

```cpp
(condition) ? value_if_true : value_if_false;
```

### 🧪 Example:

```cpp
int age = 18;
string result = (age >= 18) ? "Adult" : "Minor";
cout << result << endl;
```

### 🧠 Reasoning:

* **One-line `if-else`**, good for simple decisions.
* Useful in compact UI logic, default value selection, etc.

---

## 🔹 8. Bitwise Operators

| Operator | Meaning     | Example  |     |     |
| -------- | ----------- | -------- | --- | --- |
| `&`      | AND         | `a & b`  |     |     |
| \`       | \`          | OR       | \`a | b\` |
| `^`      | XOR         | `a ^ b`  |     |     |
| `~`      | NOT         | `~a`     |     |     |
| `<<`     | Left shift  | `a << 1` |     |     |
| `>>`     | Right shift | `a >> 1` |     |     |

### 🧪 Example:

```cpp
int a = 5, b = 3;
cout << (a & b) << endl;  // 1
```

### 🧠 Reasoning:

* Used in **hardware, encryption, compression**, and **performance hacks**.
* `a << 1` is the same as multiplying `a` by 2.

---

## 🔹 9. Operator Precedence & Associativity

### 📊 Operator Precedence (Top to Bottom):

1. `()`
2. `++`, `--`
3. `*`, `/`, `%`
4. `+`, `-`
5. `<`, `<=`, `>`, `>=`
6. `==`, `!=`
7. `&&`
8. `||`
9. `=`, `+=`, `-=`, etc.

### 🔄 Associativity:

* Most operators are **left to right**.
* Assignment (`=`) and ternary are **right to left**.

### 🧪 Example:

```cpp
int result = 5 + 3 * 2;  // 5 + (3 * 2) = 11
```

---

## 🔹 10. Practice Exercises & Recap

### 🧪 Exercises:

1. Write a program to take two integers and:

   * Add, subtract, multiply, divide them
   * Check which is larger
   * Use ternary to display "Equal" or "Not equal"
2. Take an integer and:

   * Check if it's even using `%`
   * Double it using `<<`
   * Set a boolean flag using `&&` and `||`

---

## ✅ Summary

| Operator Type | Used For                       |
| ------------- | ------------------------------ |
| Arithmetic    | Mathematical operations        |
| Relational    | Comparisons                    |
| Logical       | Conditional logic              |
| Assignment    | Variable updates               |
| Bitwise       | Low-level memory manipulations |
| Unary         | Increment/Decrement            |
| Ternary       | Compact decisions              |

---

## 📚 Optional Homework

* Write a mini calculator using `switch-case`.
* Explore how to toggle a bit using XOR (`^`).
* Create a program using logical operators for access control (e.g., login simulation).
