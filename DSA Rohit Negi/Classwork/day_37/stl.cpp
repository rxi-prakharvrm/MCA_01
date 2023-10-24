#include <iostream>
#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int main() {
    vector<int> v = {3, 6, 2, 6, 1, 8};
    for(auto itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    for(auto itr = v.rbegin(); itr != v.rend(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }
    return 0;
}