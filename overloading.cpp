#include <iostream>

class MyClass {
public:
    // Overloaded function with different parameter lists
    void print() {
        std::cout << "No parameters\n";
    }

    void print(int x) {
        std::cout << "Integer parameter: " << x << "\n";
    }

    void print(double x) {
        std::cout << "Double parameter: " << x << "\n";
    }
};

int main() {
    MyClass obj;
    obj.print();        // Calls print() with no parameters
    obj.print(10);      // Calls print(int)
    obj.print(3.14);    // Calls print(double)
    return 0;
}
