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