
#include <iostream>

class A {
public:
    A() {
        std::cout << "A()" << std::endl; 
    }

    ~A() {
        std::cout << "~A()" << std::endl; 
    }
};

class B : A{
public:    
    B() {
        std::cout << "B()" << std::endl; 
    }

    ~B() {
        std::cout << "~B()" << std::endl; 
    }
};

int main(void)
{
    B b; 
    std::cout << "test" << std::endl;
}