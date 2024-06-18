#include <iostream>
using namespace std;

class MyClass {
public:
    int *data;
    int size;
    int *ref_counter;
    
    MyClass() : data(nullptr), size(0), ref_counter(nullptr) {};
    MyClass(int _size) {
        size = _size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = i;
        ref_counter = new int;
        *ref_counter = 1;
        cout << "in constructor : " << endl;
        cout << "0x" << ref_counter << " : " << *ref_counter << endl;        
    }

    MyClass(const MyClass &other)
    {
        cout << "Copy Constructor" << endl;
        if (this != &other) {
            this->data = other.data;
            this->ref_counter = other.ref_counter;
            this->size = other.size;

            *ref_counter = *ref_counter + 1;
        }
        cout << "0x" << ref_counter << " : " << *ref_counter << endl;        

    }

    MyClass& operator=(const MyClass &other)
    {
        cout << "Copy Assignment Operator" << endl;

        if (this != &other) {
            this->data = other.data;
            this->ref_counter = other.ref_counter;
            this->size = other.size;
            *ref_counter = *ref_counter + 1;
        }
        cout << "0x" << ref_counter << " : " << *ref_counter << endl;        

        return *this;
    }

    ~MyClass () {
        cout << "Destructor" << endl;
        *ref_counter = *ref_counter - 1;
        cout << "0x" << ref_counter << " : " << *ref_counter << endl;        
        if (*ref_counter == 0)
        {
            delete[] data;
            delete ref_counter;
        }
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2, obj3, obj4;
    obj2 = obj3 = obj4 = obj1;

    return 0;
}
