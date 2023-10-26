#include <iostream>
using namespace std;

int sumOfDigitsOfANumber(int num) {
    int rem, sum = 0;
    
    // base considion
    if(num%10 == num) return num;

    // processing part
    rem = num % 10;
    sum = sum + rem;

    // recursion
    sumOfDigitsOfANumber(num/10);

    return sum;
}

int main() {
    int num = 12345;
    cout << sumOfDigitsOfANumber(num);
    return 0;
}