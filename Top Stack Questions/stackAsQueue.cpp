#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Queue using stack, Push Efficient
// class QueueUsingStack {
//     public:
//     stack<int> first;
//     stack<int> second;

//     public:
//     QueueUsingStack() {
        
//     }

//     void myPush(int item) {
//         first.push(item);
//     }

//     int myPop() {
//         while(!first.empty()) {
//             second.push(first.top());
//             first.pop();
//         }

//         int removed = second.top();
//         second.pop();

//         while(!second.empty()) {
//             first.push(second.top());
//             second.pop();
//         }

//         return removed;
//     }

//     bool isEmpty() {
//         return first.empty();
//     }
// };

// Queue using stack, Pop efficient
class QueueUsingStack {
    public:
    stack<int> first;
    stack<int> second;

    void myPush(int item) {
        while(!first.empty()) {
            second.push(first.top());
            first.pop();
        }

        first.push(item);

        while(!second.empty()) {
            first.push(second.top());
            second.pop();
        }
    }

    int myPop() {
        int removed = first.top();
        first.pop();
        return removed;
    }
};

int main() {
    QueueUsingStack stk1;
    QueueUsingStack stk2;

    // Insertion in Queue
    stk1.myPush(1);
    stk1.myPush(2);
    stk1.myPush(3);

    // Popping from front
    cout << stk1.myPop() << " ";
    cout << stk1.myPop() << " ";
    cout << stk1.myPop() << " ";
    return 0;
}