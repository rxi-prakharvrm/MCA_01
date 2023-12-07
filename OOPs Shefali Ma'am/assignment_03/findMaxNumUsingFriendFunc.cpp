#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Num1 {
    int num1 = 10;

    friend int maxNum();
};

class Num2 {
    int num2 = 20;

    friend int maxNum();
};

int maxNum() {
    Num1 n1;
    Num2 n2;
    return (n1.num1 > n2.num2) ? n1.num1 : n2.num2;
}

int main() {
    cout << maxNum() << endl;
    return 0;
}