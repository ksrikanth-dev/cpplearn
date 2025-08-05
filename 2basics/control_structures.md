# 🧭 C++ Control Structures

## 🔰 What are Control Structures?

Control structures **control the flow** of a program — deciding **which code runs, in what sequence, how many times**, and **under what conditions**.

---

## 🗂️ Categories of Control Structures

| Type                       | Keywords                              |
| -------------------------- | ------------------------------------- |
| 1. **Decision Making**     | `if`, `else`, `else if`, `switch`     |
| 2. **Loops (Iteration)**   | `for`, `while`, `do...while`          |
| 3. **Jumping (Branching)** | `break`, `continue`, `goto`, `return` |

---

# ✅ 1. Decision-Making Statements

---

### 🔹 `if` Statement

**🧠 Reasoning:**
Use `if` when you want to run code **only if** a condition is true.

```cpp
int age = 20;
if (age >= 18) {
    cout << "You are eligible to vote." << endl;
}
```

---

### 🔹 `if...else`

**🧠 Reasoning:**
Use when you need to choose **between two options**.

```cpp
int age = 16;
if (age >= 18) {
    cout << "Adult" << endl;
} else {
    cout << "Minor" << endl;
}
```

---

### 🔹 `else if`

**🧠 Reasoning:**
Use for **multiple conditions** (like ladder logic).

```cpp
int score = 75;
if (score >= 90) {
    cout << "Grade A";
} else if (score >= 75) {
    cout << "Grade B";
} else if (score >= 60) {
    cout << "Grade C";
} else {
    cout << "Fail";
}
```
This is called chained if...else
---

### 🔹 `switch` Statement

**🧠 Reasoning:**
Use when you need to match a variable to **one of the many exact constant values**.

```cpp
int day = 2;
switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    default: cout << "Invalid Day";
}
```

---

# 🔁 2. Looping (Iteration)

---

### 🔹 `for` Loop

**🧠 Reasoning:**
Use when you know **how many times** to loop in advance.

### ✅ **Syntax:**

```cpp
for (initialization; condition; increment) {
    // code to execute repeatedly
}
```

### 🧾 Example:

```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Hello " << i << endl;
}
```

---

### 🧠 **Explanation of Components:**

| Component          | Purpose                                            |
| ------------------ | -------------------------------------------------- |
| **Initialization** | Runs once at the beginning (e.g., `int i = 0`)     |
| **Condition**      | Checked before each iteration (e.g., `i < 5`)      |
| **Increment**      | Runs after every loop body execution (e.g., `i++`) |

---

### 🔍 **Why Use a `for` Loop?**

* When you **know the number of iterations** in advance.
* For **counters**, **array traversal**, **table generation**, etc.
* Keeps **loop logic compact and readable**.

---

## 🎯 Sample Use Cases of `for` Loop

---

### 1. ✅ Counting

```cpp
for (int i = 1; i <= 10; i++) {
    cout << i << " ";
}
// Output: 1 2 3 4 5 6 7 8 9 10
```

---

### 2. 📊 Sum of First N Numbers

```cpp
int sum = 0;
for (int i = 1; i <= 100; i++) {
    sum += i;
}
cout << "Sum = " << sum;
```

---

### 3. 📦 Array Traversal

```cpp
int arr[] = {2, 4, 6, 8};
for (int i = 0; i < 4; i++) {
    cout << arr[i] << " ";
}
```

---

### 4. 🔢 Multiplication Table

```cpp
int n = 5;
for (int i = 1; i <= 10; i++) {
    cout << n << " x " << i << " = " << n * i << endl;
}
```

---

### 5. 🔄 Nested `for` Loop (Matrix or Pattern)

```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cout << "(" << i << "," << j << ") ";
    }
    cout << endl;
}
```

---

### 6. ❗ Infinite Loop (with break)
This is equivalent to `while(true) {}` loop.
```cpp
for (;;) {
    cout << "Running... ";
    break;  // exit to prevent infinite execution
}
```

---

### 🔄 Variants of `for` Loop

| Variant      | Syntax                             | Use Case       |
| ------------ | ---------------------------------- | -------------- |
| Normal loop  | `for (int i = 0; i < n; i++)`      | Simple counter |
| Reverse loop | `for (int i = n; i > 0; i--)`      | Countdown      |
| Step-size    | `for (int i = 0; i <= 10; i += 2)` | Even numbers   |

---

### 🔐 Loop Scope 
We can define variables that are scoped only to the for loop.
These variables can't be accessed outside the for loop.

```cpp
for (int i = 0; i < 3; i++) {
    int temp = i * 10;
    cout << temp << " ";
}
// 'temp' is NOT accessible outside the loop
```
---

## ✅ Summary

| Feature      | Benefit                                      |
| ------------ | -------------------------------------------- |
| Compact form | Combines init, condition, and increment      |
| Readable     | Everything about loop control is in one line |
| Flexible     | Custom step, reverse loop, nested loops      |
| Controlled   | Best when loop count is known                |

---

### 🔹 `while` Loop

**🧠 Reasoning:**
Use when the number of iterations is **unknown** and depends on a **condition**.

```cpp
int n = 1;
while (n <= 5) {
    cout << "While loop: " << n << endl;
    n++;
}
```

---

### 🔹 `do...while` Loop

**🧠 Reasoning:**
Use when you want the loop to run **at least once** (even if condition is false).

```cpp
int n = 1;
do {
    cout << "Do while: " << n << endl;
    n++;
} while (n <= 3);
```

---

# 🔄 3. Jump Statements (Flow Altering)

---

### 🔹 `break`

**🧠 Reasoning:**
Used to **exit early** from a loop or `switch`.

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    cout << i << " ";
}
// Output: 1 2 3 4
```

---

### 🔹 `continue`

**🧠 Reasoning:**
Skip current iteration and **continue with next**.

```cpp
for (int i = 1; i <= 5; i++) {
    if (i == 3) continue;
    cout << i << " ";
}
// Output: 1 2 4 5
```

---

### 🔹 `goto`

**🧠 Reasoning:**
Rarely used today. Can jump to a labeled statement, but should be avoided for readability.

```cpp
int x = 1;
label: // we can give any custom name to the label
    cout << x << " ";
    x++;
    if (x <= 3) goto label;
```

⚠️ Use `goto` **only when absolutely necessary**, like breaking out of **deeply nested loops**.

---

### 🔹 `return`

**🧠 Reasoning:**
Exits the current function and optionally returns a value.

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

# 🔁 Combined Example — Control Flow in Action

```cpp
int number;
cout << "Enter a number between 1 and 5: ";
cin >> number;

switch (number) {
    case 1:
    case 2:
    case 3:
        for (int i = 0; i < number; i++) {
            if (i == 1) continue;  // Skip second loop
            cout << "Loop " << i << endl;
        }
        break;
    case 4:
        cout << "Calling return now.\n";
        return 0;
    default:
        cout << "Invalid choice.\n";
}
```

---

# 📌 Summary Table

| Structure           | Use Case                       | Keywords                              |
| ------------------- | ------------------------------ | ------------------------------------- |
| **Decision Making** | Condition-based code execution | `if`, `else`, `else if`, `switch`     |
| **Iteration**       | Repeating blocks of code       | `for`, `while`, `do...while`          |
| **Jumping**         | Change flow of execution       | `break`, `continue`, `goto`, `return` |

---
