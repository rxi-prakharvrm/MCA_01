#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "[(])";
    stack<char> stk;

    for(int i = 0; i < str.size(); i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
            stk.push(str[i]);
        } else if(str[i] == ']') {
            if(stk.top() == '[') {
                stk.pop();
            } else {
                break;
            }
        } else if(str[i] == '}') {
            if(stk.top() == '{') {
                stk.pop();
            } else {
                break;
            }
        } else if(str[i] == ')') {
            if(stk.top() == '(') {
                stk.pop();
            } else {
                break;
            }
        }
    }

    stk.empty() ? cout << "Balanced" << endl : cout << "Not Balanced" << endl;
    return 0;
}