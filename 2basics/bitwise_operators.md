Making use of bitwise and logical operators to solve a simple **real-world inspired problem**

---

## 💡 **Scenario: Access Control System**

You're building a simplified **security system** where users have access based on:

* Bitwise flags representing access levels.
* Logical conditions for login status and verification.

---

## 🎯 **Objective:**

Use:

* **Bitwise operators** to manage and check access rights.
* **Logical operators** to ensure the user is authenticated and verified.

---

## 🔐 **Access Rights (using Bit Flags)**

We define access rights using **bit masks**:

```cpp
const int ACCESS_READ    = 1 << 0; // 0001 = 1
const int ACCESS_WRITE   = 1 << 1; // 0010 = 2
const int ACCESS_EXECUTE = 1 << 2; // 0100 = 4
const int ACCESS_ADMIN   = 1 << 3; // 1000 = 8
```

So a user with `READ + WRITE` will have access level = `1 | 2 = 3`.

---

## ✅ **Full C++ Code Example:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Access level flags
const int ACCESS_READ    = 1 << 0; // 0001 = 1
const int ACCESS_WRITE   = 1 << 1; // 0010 = 2
const int ACCESS_EXECUTE = 1 << 2; // 0100 = 4
const int ACCESS_ADMIN   = 1 << 3; // 1000 = 8

int main() {
    string username;
    string password;
    bool isLoggedIn = false;
    bool isVerified = false;
    int userAccessLevel = 0;

    // Simulate user input
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Simulate login check
    if (username == "admin" && password == "pass123") {
        isLoggedIn = true;
        isVerified = true; // Assume email/OTP verified

        // Give full access
        userAccessLevel = ACCESS_READ | ACCESS_WRITE | ACCESS_EXECUTE | ACCESS_ADMIN;
    } else if (username == "user" && password == "user123") {
        isLoggedIn = true;
        isVerified = true;

        // Limited access
        userAccessLevel = ACCESS_READ | ACCESS_WRITE;
    } else {
        cout << "Login failed!" << endl;
    }

    // Logical operators check
    if (isLoggedIn && isVerified) {
        cout << "Login successful!" << endl;

        // Check specific permissions using bitwise AND
        if (userAccessLevel & ACCESS_READ)
            cout << "You have READ access." << endl;
        if (userAccessLevel & ACCESS_WRITE)
            cout << "You have WRITE access." << endl;
        if (userAccessLevel & ACCESS_EXECUTE)
            cout << "You have EXECUTE access." << endl;
        if (userAccessLevel & ACCESS_ADMIN)
            cout << "You have ADMIN access." << endl;
    } else if (isLoggedIn && !isVerified) {
        cout << "Please verify your email/OTP." << endl;
    }

    return 0;
}
```

---

## 🧠 **Explanation of Bitwise & Logical Operator Use:**

### ✅ Bitwise Operators:

* `|` → Combines multiple access rights:

  ```cpp
  ACCESS_READ | ACCESS_WRITE
  ```
* `&` → Checks if a user has a specific right:

  ```cpp
  if (userAccessLevel & ACCESS_ADMIN)
  ```

### ✅ Logical Operators:

* `&&` → Checks if **both conditions** are true (`isLoggedIn && isVerified`)
* `!` → Negates a condition (`!isVerified`)

---

## 🧪 Sample Output:

### 🔹 Input:

```
Enter username: user
Enter password: user123
```

### 🔹 Output:

```
Login successful!
You have READ access.
You have WRITE access.
```

---

## 🧾 Summary:

This program demonstrates:

| Concept                | How it’s used                 |
| ---------------------- | ----------------------------- |
| **Bitwise OR (`|`)**   | Combine multiple permissions  |
| **Bitwise AND (`&`)**  | Check for specific permission |
| **Logical AND (`&&`)** | Verify multiple conditions    |
| **Logical NOT (`!`)**  | Handle exceptions             |

