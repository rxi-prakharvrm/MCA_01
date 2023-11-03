#include <iostream>
#include <cmath>
using namespace std;

/*

*
* * 
* * *
* * * *
* * * * *

*/
void pattern01() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

        *
      * *
    * * *
  * * * *
* * * * *

*/

void pattern02() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 5; col > row; col--) {
            cout << "  ";
        }
        for(int col = 1; col <= row; col++)  {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

*/

void pattern03() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 5; col > row; col--) {
            cout << "  ";
        }
        for(int col = 1; col <= 2*row-1; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *

*/

void pattern04() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 1; col < row; col++) {
            cout << "  ";
        }
        for(int col = 1; col <= 2*5-(2*row-1); col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

*/

void pattern05() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 1; col <= row; col++) {
            cout << row << " ";
        }
        cout << endl;
    }
}

/*

      1
    1 2 1
  1 2 4 2 1
1 2 4 8 4 2 1

*/

void pattern06() {
    for(int row = 1; row <= 4; row++) {
        for(int col = 4; col > row; col--) {
            cout << "  ";
        }
        for(int col = 1; col <= pow(2, row-1); col *= 2) {
            cout << col << " ";
        }
        for(int col = pow(2, row-1)/2; col >= 1; col /= 2) {
            cout << col << " ";
        }
        cout << endl;
    }
}

// Counting Numbers, Characters, Letters and Spaces in the given string
void countNumsCharsLettersSpaces(string str) {
    int countSpace = 0;
    int countLetter = 0;
    int countNumber = 0;
    int countSymbol = 0;

    for(char c: str) {
        if(c == 32) {
            countSpace++;
        }
        else if((c >= 65 && c <= 65+26) || (c >= 97 && c <= 97+26)) {
            countLetter++;
        }
        else if(c >= 48 && c <= 57) {
            countNumber++;
        }
        else {
            countSymbol++;
        }
    }

    cout << "Total number of \"Spaces\" in the string: " << countSpace << endl;
    cout << "Total number of \"Letters\" in the string: " << countLetter << endl;
    cout << "Total number of \"Numbers\" in the string: " << countNumber << endl;
    cout << "Total number of \"Special Characters\" in the string: " << countSymbol << endl;
}

// Reverse the string using recursion
void reverseString(string &str, int a, int n) {
    if(a > n) {
        return;
    }
    // default swap function in c++
    swap(str[a], str[n]);

    reverseString(str, a+1, n-1);
}

int main() {
    // pattern01();
    // pattern02();
    // pattern03();
    // pattern04();
    // pattern05();
    // pattern06();

    // Count the number of spaces, letters, special characters and numbers
    string str = "CPP is a superset of C";
    // countNumsCharsLettersSpaces(str);

    // Reverse the string
    reverseString(str, 0, str.length()-1);
    cout << str << endl;
    return 0;
}