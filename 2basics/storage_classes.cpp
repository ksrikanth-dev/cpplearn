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
    int autoVar = 10;
    
    // Displaying the values of different variables
    std::cout << "Auto variable value: " << autoVar << std::endl;
    
    // Calling functions to demonstrate 'static' and 'register' variables
    staticExample();  // Will show the static variable retaining its value across calls
    staticExample();
    
    registerExample();  // Will show the register variable
    
    std::cout << "\nGlobal variable (extern): " << globalVar << std::endl;

    return 0;
}
