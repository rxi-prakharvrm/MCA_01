#include <iostream>
using namespace std;

class Student {
    public:
    int id;
    string name;

    Student(Student *DMemory) {
        DMemory = new Student(DMemory);
        cout << "Dynamic memory is created!" << endl;
    }
};

int main() {
    Student *DMemory;
    Student s(DMemory);
    return 0;
}