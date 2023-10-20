#include <iostream>
#include <math.h>
using namespace std;

// Function to convert a decimal number to its equivalent binary
int decimalToBinary(int n) {
    int lastDigit = 0, binaryNumber = 0, exponent = 0;

    while(n > 0) {
        lastDigit = n % 2;
        binaryNumber += lastDigit * pow(10, exponent);
        n /= 2;
        exponent++;
    }

    return binaryNumber;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    cout << "Binary conversion of the decimal number \'" << decimalNumber << "\' is: " << decimalToBinary(decimalNumber) << endl;
    return 0;
}