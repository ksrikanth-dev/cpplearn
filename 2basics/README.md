26/03/2025:
***********
- install c++ from extensions
- install c++ extension pack
- install MinGW https://code.visualstudio.com/docs/cpp/config-mingw

==================================================================

- **Data types** (primitive and user-defined)
- **Variable types** (local, global, static)
- **Variable scope** (local, global, static)
- **Constants** (const and `#define`)
- **Literals** (integer, floating-point, character, string)
- **Basic input and output** using **streams** (cin, cout)

```cpp
#include <iostream>
#include <string>  // for string data type
#include <limits>  // for numeric limits

// Global variable example
int globalVar = 10;

// Constants
const double PI = 3.14159;  // constant (using const)
#define MAX_SIZE 100  // constant (using #define)

using namespace std;

// Function to demonstrate local and static variables
void demoVariableScope() {
    // Local variable
    int localVar = 20;
    
    // Static variable
    static int staticVar = 30; // Retains its value between function calls
    
    // Modify staticVar to show that its value is retained
    staticVar += 10;

    cout << "Inside demoVariableScope():\n";
    cout << "localVar = " << localVar << "\n";
    cout << "staticVar (static) = " << staticVar << "\n";
}

int main() {
    // Primitive data types
    int intVar = 5;             // Integer type
    double doubleVar = 3.14;    // Double (floating-point) type
    char charVar = 'A';         // Character type
    bool boolVar = true;        // Boolean type
    float floatVar = 2.71f;     // Float type (explicit 'f' for float literal)
    
    // String literal (C++ string class)
    string strVar = "Hello, C++!";
    
    // Input/Output demonstration
    int userInput;
    cout << "Enter an integer: ";
    cin >> userInput;
    cout << "You entered: " << userInput << endl;

    // Constants and literals
    cout << "\nConstants and Literals:\n";
    cout << "PI = " << PI << endl;                // Constant using const
    cout << "MAX_SIZE = " << MAX_SIZE << endl;    // Constant using #define
    cout << "String literal: " << strVar << endl;
    cout << "Character literal: " << charVar << endl;

    // Variable scope demonstration
    cout << "\nVariable Scope Demo:\n";
    demoVariableScope();  // Local variable demo
    
    // Showing numeric limits for int and double
    cout << "\nNumeric Limits:\n";
    cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
    cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
    cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;
    cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;

    // Variable types (local, static, and global) demonstration
    cout << "\nGlobal Variable (globalVar) = " << globalVar << endl;
    
    // Demonstrating the behavior of static variables in function calls
    cout << "\nDemonstrating static variables:\n";
    demoVariableScope(); // Static variable should retain its value

    // Type casting (Explicit and Implicit)
    cout << "\nDemonstrating Type Casting:\n";
    double result1 = (double)intVar + doubleVar;  // Explicit type casting
    cout << "Result of type casting int to double: " << result1 << endl;

    double result2 = static_cast<double>(intVar) + doubleVar;  // Explicit type casting
    cout << "Result of type casting int to double: " << result2 << endl;
    
    // Implicit type casting
    int sum = intVar + doubleVar;  // Implicit casting of double to int
    cout << "Implicit type casting: " << sum << endl;

    // Demonstrating scope of variables
    {
        // Local block scope
        int blockVar = 50;
        cout << "\nInside block: blockVar = " << blockVar << endl;
    }
    // blockVar is not accessible here due to its local scope

    return 0;
}
```

### Key Points in the Code:

1. **Data Types**:
   - **Primitive Types**: `int`, `double`, `char`, `bool`, `float`.
   - **User-defined Types**: `string` (for C++ standard strings).
   
2. **Variable Types**:
   - **Local Variables**: Defined within a function and accessible only within that function.
   - **Global Variables**: Defined outside any function and accessible throughout the program.
   - **Static Variables**: Retain their value between function calls, unlike local variables.

3. **Variable Scope**:
   - Local scope is limited to the function or block in which the variable is defined.
   - Global variables can be accessed anywhere in the program.
   - Static variables retain their value across function calls but are scoped to the function.

4. **Constants**:
   - **`const`**: Defines a constant that cannot be changed once initialized.
   - **`#define`**: Preprocessor macro to define constants.

5. **Literals**:
   - Integer, floating-point, character, and string literals are demonstrated.

6. **Input/Output**:
   - **`cin`**: Used for input (reading values from the user).
   - **`cout`**: Used for output (printing values to the console).

7. **Type Casting**:
   - **Explicit**: `static_cast` to convert one data type to another.
   - **Implicit**: The compiler automatically converts types when necessary.

### Output Example:

```
Enter an integer: 42
You entered: 42

Constants and Literals:
PI = 3.14159
MAX_SIZE = 100
String literal: Hello, C++!
Character literal: A

Variable Scope Demo:
localVar = 20
staticVar (static) = 40

Numeric Limits:
Maximum value for int: 2147483647
Minimum value for int: -2147483648
Maximum value for double: 1.79769e+308
Minimum value for double: 2.22507e-308

Global Variable (globalVar) = 10

Demonstrating static variables:
localVar = 20
staticVar (static) = 50

Demonstrating Type Casting:
Result of type casting int to double: 8.14
Implicit type casting: 7

Inside block: blockVar = 50
```

==================================================================

**type qualifiers** (`const`, `volatile`, and `mutable`):

```cpp
#include <iostream>

// Using the `const` qualifier
void demoConst() {
    const int a = 10;  // `a` is a constant and cannot be modified
    std::cout << "Constant value: " << a << std::endl;
    // a = 20;  // Uncommenting this line would result in a compile-time error
}

// Using the `volatile` qualifier
volatile int flag = 0;  // The `volatile` qualifier tells the compiler not to optimize access to `flag`

void demoVolatile() {
    std::cout << "Flag before modification: " << flag << std::endl;
    flag = 1;  // Modifying the volatile flag
    std::cout << "Flag after modification: " << flag << std::endl;
}

// Using the `mutable` qualifier in a class
class DemoClass {
public:
    mutable int counter;  // `counter` can be modified even in const methods

    DemoClass() : counter(0) {}

    void modifyCounter() const {
        counter++;  // `counter` can still be modified in a const function due to `mutable`
        std::cout << "Counter (modified in const method): " << counter << std::endl;
    }
};

int main() {
    // Demonstrate `const`
    std::cout << "Demonstrating const qualifier:" << std::endl;
    demoConst();
    
    // Demonstrate `volatile`
    std::cout << "\nDemonstrating volatile qualifier:" << std::endl;
    demoVolatile();
    
    // Demonstrate `mutable`
    std::cout << "\nDemonstrating mutable qualifier:" << std::endl;
    const DemoClass obj;
    obj.modifyCounter();  // This should work even though the object is `const`
    
    return 0;
}
```

### Explanation:

1. **`const`**:
   - The variable `a` is declared as `const`, which means its value cannot be modified after initialization. Uncommenting the line where `a` is modified will cause a compile-time error.
   
2. **`volatile`**:
   - The variable `flag` is declared as `volatile`, which tells the compiler not to optimize or cache its value. This is important in scenarios where the value of a variable can change unexpectedly, such as in hardware or multithreaded programs. In this case, we modify `flag` in the `demoVolatile` function.

3. **`mutable`**:
   - In the `DemoClass`, the member `counter` is declared as `mutable`. This allows the `counter` to be modified in a `const` member function (like `modifyCounter`), even though the object itself is marked as `const`. This is useful when you want certain data in an object to be mutable, regardless of whether the object is const.

### Output Example:

```
Demonstrating const qualifier:
Constant value: 10

Demonstrating volatile qualifier:
Flag before modification: 0
Flag after modification: 1

Demonstrating mutable qualifier:
Counter (modified in const method): 1
```

### Key Concepts:
- **`const`** ensures that a variable cannot be modified.
- **`volatile`** tells the compiler not to optimize access to a variable, which is necessary when the variable can be changed outside of the program's control (e.g., by hardware or another thread).
- **`mutable`** allows modifying a class member even if the object is declared as `const`.


==================================================================

In C++, **storage classes** define the scope, visibility, and lifetime of variables. There are four types of storage classes:

1. **`auto`**: The default storage class for local variables.
2. **`register`**: Suggests that the variable should be stored in a CPU register, instead of RAM, to make it faster (though the compiler decides if it will actually use a register).
3. **`static`**: Retains the variable’s value between function calls, and its lifetime is the entire duration of the program.
4. **`extern`**: Declares a variable that is defined in another file, allowing it to be shared between multiple files.

Here's a simple program that demonstrates the usage of **storage classes** in C++:

```cpp
#include <iostream>

// Global variable with 'extern' storage class, defined outside of any function.
extern int globalVar;  // Declaration, the definition is outside the main function

void staticExample() {
    // A local variable with 'static' storage class
    static int staticVar = 0;  // This variable retains its value across function calls
    std::cout << "Static variable value: " << staticVar << std::endl;
    staticVar++;  // Increment the static variable
}

void registerExample() {
    // A local variable with 'register' storage class
    register int registerVar = 5;  // Suggests to the compiler to store in a register
    std::cout << "Register variable value: " << registerVar << std::endl;
    registerVar++;  // Increment the register variable
}

int globalVar = 100;  // Definition of the global variable declared with 'extern'

int main() {
    // Local variable with 'auto' storage class (default in C++)
    auto int autoVar = 10;
    
    // Displaying the values of different variables
    std::cout << "Auto variable value: " << autoVar << std::endl;
    
    // Calling functions to demonstrate 'static' and 'register' variables
    staticExample();  // Will show the static variable retaining its value across calls
    staticExample();
    
    registerExample();  // Will show the register variable
    
    std::cout << "\nGlobal variable (extern): " << globalVar << std::endl;

    return 0;
}
```

### Explanation:
1. **`auto`**:
   - `auto` is the default storage class for local variables, meaning `autoVar` is a local variable with automatic storage duration. It is automatically created when the function is called and destroyed when the function exits.
   
2. **`static`**:
   - `staticVar` is a **static variable**. Static variables retain their value between function calls. In the `staticExample()` function, `staticVar` is initialized to `0` the first time the function is called, and it increments each time the function is called, retaining its value across multiple calls.

3. **`register`**:
   - `registerVar` is a **register variable**. It suggests to the compiler that the variable should be stored in a CPU register for faster access. While this is only a suggestion, the compiler may or may not follow it.

4. **`extern`**:
   - `globalVar` is a **global variable** that is defined outside of any function. The keyword `extern` is used to declare the variable in a different file. In this case, `globalVar` is defined globally (outside `main()`), and it is accessed within the `main()` function.

### Output Example:

```
Auto variable value: 10
Static variable value: 0
Static variable value: 1
Register variable value: 5

Global variable (extern): 100
```

### Key Takeaways:
- **`auto`**: The default for local variables.
- **`static`**: Retains the value of a variable between function calls.
- **`register`**: Suggests to the compiler to store the variable in a CPU register.
- **`extern`**: Allows variables to be declared outside the current file, making them accessible in other files.
