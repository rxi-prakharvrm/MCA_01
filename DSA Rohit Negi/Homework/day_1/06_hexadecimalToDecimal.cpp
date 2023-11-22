#include <iostream>
#include <cmath>
using namespace std;

int letterToDigit(char hexDigit) {
    if(hexDigit == 'A' || hexDigit == 'a') return 10;
    else if(hexDigit == 'B' || hexDigit == 'b') return 11;
    else if(hexDigit == 'C' || hexDigit == 'c') return 12;
    else if(hexDigit == 'D' || hexDigit == 'd') return 13;
    else if(hexDigit == 'E' || hexDigit == 'e') return 14;
    else if(hexDigit == 'F' || hexDigit == 'f') return 15;
    else return (hexDigit - '0');
}

int hexToDecimal(string hex) {
    int decimalNumber = 0, lastDigit = 0, exponent = 0;

    for(int i = hex.size()-1; i >= 0; i--) {
        lastDigit = letterToDigit(hex[i]);
        if(lastDigit >= 0 && lastDigit <= 15) {
            decimalNumber += lastDigit * pow(16, exponent);
            exponent++;
        } else {
            std::cout << "Please enter a valid hexadecimal number!" << std::endl;
            exit(0);
        }
    }

    return decimalNumber;
}

int main() {
    string hex = "1F";
    int decimal = hexToDecimal(hex);
    cout << "Decimal equivalent of hexadecimal number " << hex << " is: " << decimal << endl;
    return 0;
}