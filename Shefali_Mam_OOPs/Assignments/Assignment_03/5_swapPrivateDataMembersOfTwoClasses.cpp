#include <iostream>
using namespace std;

class class_2;

class class_1 {
    int num1 = 10;

    friend void swapDataMembers(class_1 &c1, class_2 &c2);
    friend void printSwappedDataMembers(class_1 &c1, class_2 &c2);
};

class class_2 {
    int num2 = 20;

    friend void swapDataMembers(class_1 &c1, class_2 &c2);
    friend void printSwappedDataMembers(class_1 &c1, class_2 &c2);
};

void swapDataMembers(class_1 &c1, class_2 &c2) {
    swap(c1.num1, c2.num2);
}

void printSwappedDataMembers(class_1 &c1, class_2 &c2) {
    cout << "num1: " << c1.num1 << endl;
    cout << "num2: " << c2.num2 << endl;
}

int main() {
    class_1 c1;
    class_2 c2;
    swapDataMembers(c1, c2);
    printSwappedDataMembers(c1, c2);
    return 0;
}
