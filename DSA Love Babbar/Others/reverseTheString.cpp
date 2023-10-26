#include <iostream>
using namespace std;

void reverseTheString(string &str, int i, int j) {
    if(i > j) return;

    swap(str[i], str[j]);
    i++;
    j--;

    return reverseTheString(str, i, j);
}

int main() {
    string name = "prakhar";
    reverseTheString(name, 0, name.length()-1);
    cout << name << endl;
    return 0;
}