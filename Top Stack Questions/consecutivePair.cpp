#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ================================= Pseudo Code ===================================

// function consecutivePair(stack stk):
//     create a copy of stack stk and store it in reserveStk
//     create a new stack called newStk
//     initialize counter to 0

//     # Count the number of elements in the original stack
//     while stk is not empty:
//         pop an element from stk
//         increment counter by 1

//     # Restore the original stack
//     stk = reserveStk

//     # If the number of elements is odd, remove the top element
//     if counter is not even:
//         pop the top element from stk

//     # Compare consecutive pairs in the stack
//     while stk is not empty:
//         push the top element of stk onto newStk
//         pop the top element from stk

//         # Check if the pair is consecutive (differ by 1)
//         if newStk.top() is equal to (stk.top() + 1) or newStk.top() is equal to (stk.top() - 1):
//             push stk.top() onto newStk
//             pop the top element from stk
//             pop the top element from newStk
//             pop the top element from newStk
//         else:
//             return False

//     # If all consecutive pairs are found and removed, newStk should be empty
//     if newStk is empty:
//         return True
//     else:
//         return False


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