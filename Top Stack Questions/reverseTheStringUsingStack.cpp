#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "GeeksQuiz";
    stack<char> stk;

    for(int i = 0; i < str.length(); i++) {
        stk.push(str[i]);
    }

    int index = 0;
    while(!stk.empty()) {
        str[index] = stk.top();
        stk.pop();
        index++;
    }

    cout << str << endl;
    return 0;
}