#include <iostream>

class Base {
public:
    // Virtual function to be overridden
    virtual void show() {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    // Overriding the show() function of the base class
    void show() override {
        std::cout << "Derived class\n";
    }
};

int main() {
    Base* ptrBase = new Derived();  // Base class pointer pointing to Derived class object
    ptrBase->show();  // Calls the overridden function in the Derived class
    delete ptrBase;   // Remember to delete allocated memory
    return 0;
}
