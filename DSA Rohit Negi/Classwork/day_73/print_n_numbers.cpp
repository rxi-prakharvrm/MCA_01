#include <iostream>
using namespace std;

int printNumbers(int num) {
    if(num == 0) return 0;
    cout << num << " ";
    printNumbers(num-1);
}

int main() {
    printNumbers(5);
    return 0;
}