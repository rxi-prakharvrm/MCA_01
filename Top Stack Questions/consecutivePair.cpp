#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool consecutivePair(stack<int> &stk) {
    stack<int> reserveStk = stk;
    stack<int> newStk;
    int counter = 0;
    while(!stk.empty()) {
        stk.pop();
        counter++;
    }
    stk = reserveStk;

    if(counter % 2 != 0) stk.pop();

    while(!stk.empty()) {
        newStk.push(stk.top());
        stk.pop();

        if(newStk.top() == stk.top() + 1 || newStk.top() == stk.top() - 1) {
            newStk.push(stk.top());
            stk.pop();
            newStk.pop();
            newStk.pop();
        } else {
            return false;
        }
    }

    return newStk.empty() ? true : false;
}

int main() {
    stack<int> stk;
    stk.push(4);
    stk.push(5);
    stk.push(-1);
    stk.push(-2);
    stk.push(11);
    stk.push(10);
    stk.push(-3);
    stk.push(-2);
    stk.push(-8);

    cout << consecutivePair(stk) << endl;
    return 0;
}