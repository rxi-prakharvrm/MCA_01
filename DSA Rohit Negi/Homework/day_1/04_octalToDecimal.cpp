#include <iostream>
#include <cmath>

// Function to convert the binary number into decimal number
int octalToDecimal(int n) {
    int decimalNumber = 0, lastDigit = 0, exponent = 0;

    while(n > 0) {
        lastDigit = n % 10;
        if(lastDigit >= 0 && lastDigit <= 7) {
            decimalNumber += lastDigit * pow(8, exponent);
            n /= 10;
            exponent++;
        } else {
            std::cout << "Please enter a valid octal number!" << std::endl;
            exit(0);
        }
    }

    return decimalNumber;
}

int main() {
    int octalNumber;
    std::cout << "Enter the octal number: ";
    std::cin >> octalNumber;
    std::cout << "Decimal equivalent to this octal number \'" << octalNumber << "\' is: " << octalToDecimal(octalNumber) << std::endl;
    return 0;
}