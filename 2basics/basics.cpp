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