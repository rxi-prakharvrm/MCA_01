#include <iostream>
#include <fstream>
using namespace std;

main() {
    fstream MyFile("filename.txt");
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();

    string myText;
    ifstream MyReadFile("filename.txt");
    while(getline(MyReadFile, myText)) {
        cout << myText;
    }
    MyFile.close();
    MyReadFile.close();
}
