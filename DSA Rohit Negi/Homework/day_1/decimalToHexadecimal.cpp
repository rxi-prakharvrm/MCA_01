#include <iostream>
#include <math.h>
using namespace std;

// Function to convert a decimal number to its equivalent binary
string decimalToBinary(int n) {
    int lastDigit = 0;
    string hexDigit;
    string hexValue;

    // Cpp builtin function to convert decimal number to hexadecimal
    // cout << hex << n << endl;

    while(n > 0) {
        lastDigit = n % 16;
        
        if(lastDigit < 10) {
            hexDigit = '0' + lastDigit;
        } else {
            hexDigit = 'A' + (lastDigit - 10);
        }

        hexValue = hexDigit + hexValue;
        
        n /= 16;
    }

    return hexValue;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    cout << "Hexadecimal equivalent of the decimal number \'" << decimalNumber << "\' is: " << decimalToBinary(decimalNumber) << endl;
    return 0;
}