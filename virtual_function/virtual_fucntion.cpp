#include <iostream>
using namespace std;

class Base {
public:
    void print() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base *bptr;
    Derived d;
    bptr = &d;
    bptr->print();
    return 0;
}
