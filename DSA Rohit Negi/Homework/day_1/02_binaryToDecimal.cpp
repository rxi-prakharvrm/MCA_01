#include <iostream>
#include <cmath>

// Function to convert the binary number into decimal number
int binaryToDecimal(int n) {
    int decimalNumber = 0, lastDigit = 0, exponent = 0;

    while(n > 0) {
        lastDigit = n % 10;
        if(lastDigit == 0 || lastDigit == 1) {
            decimalNumber += lastDigit * pow(2, exponent);
            n /= 10;
            exponent++;
        } else {
            std::cout << "Please enter a valid binary number!" << std::endl;
            exit(0);
        }
    }

    return decimalNumber;
}

int main() {
    int binaryNumber;
    std::cout << "Enter the binary number: ";
    std::cin >> binaryNumber;
    std::cout << "Decimal equivalent to this binary number \'" << binaryNumber << "\' is: " << binaryToDecimal(binaryNumber) << std::endl;
    return 0;
}