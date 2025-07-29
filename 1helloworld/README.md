# 🧑‍🏫 **Introduction to C++ & First Program**

---

## 🎯 **Learning Objectives**

By the end of this session, you will:

* Understand what C++ is and its significance.
* Set up a development environment and write your first C++ program.
* Understand the structure and components of a C++ program.
* Use variables, data types, and basic input/output.
* Apply these concepts in small, hands-on coding tasks.

---

## 📌 Introduction to C++

### 🧠 What is C++?

* **Definition:** C++ is a **general-purpose, compiled, statically-typed language** that supports **procedural, object-oriented, and generic programming**.
* **Invented by:** Bjarne Stroustrup in 1983 as an enhancement to C language.
* **Compiled Language:** C++ code is converted into machine code using a compiler.

### 🎯 Why C++ Still Matters Today:

| Use Case                | Explanation                                                                        |
| ----------------------- | ---------------------------------------------------------------------------------- |
| Game Development        | C++ is used in engines like Unreal Engine for performance-intensive features.      |
| System Software         | Operating systems, embedded systems, drivers—where low-level control is essential. |
| Competitive Programming | STL gives C++ an edge with ready-to-use containers and algorithms.                 |
| Finance/Trading Systems | Requires high-performance real-time systems—C++ excels here.                       |

---

## 📌 Setting Up Your C++ Environment

### 🛠️ Tools You Need:

* **Compiler:** GCC (Linux/macOS), MinGW (Windows), or MSVC (Microsoft).
* **IDE/Editor:** Code::Blocks, Visual Studio, VS Code, or even an online compiler (e.g., [replit](https://replit.com/~), [cpp.sh](http://cpp.sh)).

### 🔄 Compilation Flow:

```plaintext
Your Code (.cpp) → Compiler (GCC/g++) → Executable → Run
```

---

## 📌 Your First C++ Program – Hello, World!

### 📄 Code:

```cpp
#include <iostream> // Preprocessor directive to include standard I/O
using namespace std;

int main() {
    cout << "Hello, World!" << endl; // Output to console
    return 0; // Exit status
}
```

### 🧩 Code Breakdown:

| Line                   | Explanation                                         |
| ---------------------- | --------------------------------------------------- |
| `#include <iostream>`  | Includes the input/output library.                  |
| `using namespace std;` | Allows direct use of `cout`, `cin` without `std::`. |
| `int main()`           | Entry point of any C++ program.                     |
| `cout << "..."`        | Sends output to standard console.                   |
| `return 0;`            | Indicates successful program termination.           |

### ⚙️ Behind the Scenes:

* The compiler translates your code to machine-level instructions.
* `cout` writes to `stdout`, and `endl` inserts a newline.

---

## 📌 Input and Output – `cin`, `cout`

### 🧾 Concept:

* `cout` → Outputs data to the screen.
* `cin` → Takes input from the keyboard.

### 🧪 Code Example:

```cpp
#include <iostream> // for io stream objects
#include <limits>  // for numeric limits
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << ", you are " << age << " years old." << endl;

    // Showing numeric limits for int and double
    cout << "\nNumeric Limits:\n";
    cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
    cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
    cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;
    cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;

    return 0;
}
```

### ⚠️ Tip:

* `cin` reads **up to the first space**. Use `getline(cin, name)` to capture full names.

---

## 📌 Variables and Data Types

### 🧠 What Are Variables?

Variables are names for memory locations used to store values that your program can manipulate.

### 📊 Common Data Types:

| Type     | Example      | Use Case                      |
| -------- | ------------ | ----------------------------- |
| `int`    | 10           | Whole numbers                 |
| `float`  | 3.14f        | Small decimals                |
| `double` | 3.141592     | High-precision decimals       |
| `char`   | 'A'          | Single characters             |
| `bool`   | true / false | Logical conditions            |
| `string` | "Hello"      | Text (need `<string>` header) |

### 🧪 Code Example:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 20;
    float temp = 98.6f;
    char grade = 'A';
    bool isPass = true;
    string name = "Alice";

    cout << "Student: " << name << "\nAge: " << age << "\nGrade: " << grade << endl;
    return 0;
}
```

### 🧱 Constants:

```cpp
const float PI = 3.14159;
```

### ❓ Why Learn This?

Understanding data types lets you:

* Use memory efficiently.
* Prevent type-related bugs.
* Choose correct variables for performance and correctness.

---

## 📌 Comments and Code Structure

### 🖋️ Types of Comments:

* **Single-line:** `// This is a comment`
* **Multi-line:**

```cpp
/*
This is a
multi-line comment
*/
```

### 🧑‍💼 Why Use Comments?

* Document your intent.
* Help others (and future you) understand code.
* Clarify logic in long sections.

---

## 📌 Hands-on Coding Exercises

### 🧪 Exercise 1:

Write a program that:

* Takes user input for name and city.
* Outputs a greeting like: “Hello Rahul from Hyderabad!”

### 🧪 Exercise 2:

Create a program that:

* Declares one variable of each basic type.
* Outputs all values.

---

## 📌 Summary & Q\&A

### 🧾 Summary:

| Concept        | What You Learned                                             |
| -------------- | ------------------------------------------------------------ |
| C++ Language   | High-performance, compiled language used in many industries. |
| Environment    | Tools needed to write and run C++ programs.                  |
| `main()`       | Entry point for execution.                                   |
| `cout` / `cin` | Standard ways to handle output and input.                    |
| Variables      | Temporary named storage in memory.                           |
| Data Types     | Determine size, precision, and use of data.                  |

---

## 💻 Task:

* Write a program that:

  * Takes user's name, age, and city.
  * Outputs a customized introduction.
* Swap two numbers using a temporary variable.

---
