#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the file
    ifstream inputFile("example.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // String to search for
    string searchString = "target_string";

    // Variables to store line number and current line
    int lineNumber = 0;
    string line;

    // Process each line in the file
    while (getline(inputFile, line)) {
        ++lineNumber;

        // Check if the line contains the search string
        if (line.find(searchString) != string::npos) {
            cout << "String found at line " << lineNumber << ": " << line << endl;
        }
    }

    // Close the file
    inputFile.close();

    return 0;
}
