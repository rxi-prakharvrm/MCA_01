#include <iostream>
using namespace std;

class Student {
    public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    Student(Student &obj) {
        this->id = obj.id;
        this->name = obj.name;
        this->age = obj.age;
    }
};

int main() {
    Student stu1(1, "Varun", 23);
    Student stu2(stu1);

    cout << endl << "Details of Stu1 -------------" << endl << endl;
    cout << "Id: " << stu1.id << endl;
    cout << "Name: " << stu1.name << endl;
    cout << "Age: " << stu1.age << endl;

    cout << "\n==================================\n";

    cout << endl << "Details of Stu2 -------------" << endl << endl;
    cout << "Id: " << stu2.id << endl;
    cout << "Name: " << stu2.name << endl;
    cout << "Age: " << stu2.age << endl;
    return 0;
}