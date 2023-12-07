#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Manager {
    public:
    string name;
    int age;
};

int main() {
    Manager m[3];
    int size = sizeof(m) / sizeof(m[0]);
    for(int i = 0; i < size; i++) {
        cout << "Enter the name of manager " << i+1 << ": ";
        cin >> m[i].name;
        cout << "Enter the age of manager " << i+1 << ": ";
        cin >> m[i].age;
    }

    for(int i = 0; i < size; i++) {
        cout << "Age of " << m[i].name << " is " << m[i].age << endl;
    }

    return 0;
}