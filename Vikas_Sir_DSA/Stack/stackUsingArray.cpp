#include <iostream>
using namespace std;

// stack class
class Stack {
    public:
    int top = -1;
    int n = 100;

    // dynamic memory allocation of size n with each of size int using malloc
    int* ptr = (int *) malloc (n*sizeof(int));

    // dynamic memory allocation of size n with each of size int using calloc
    int* ptr = (int *) calloc (n, sizeof(int));

    // checking if the stack is empty or not
    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }

    // checking if the stack is full or not
    bool isFull() {
        if(top == n) {
            return true;
        } else {
            return false;
        }
    }

    // push elements in stack
    void push(int value) {
        if(isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            ptr[++top] = value;
            // cout << ptr[top] << " pushed successfully!" << endl;
        }
    }

    // pop stack elements
    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << ptr[top] << " poped successfully!" << endl;
            top--;
        }
    }

    int getTop() {
        return ptr[top];
    }

    // displaying the elements of the stack
    void display() {
        if(isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        for(int i = 0; i <= top; i++) {
            cout << ptr[i] << " ";
        }

        cout << endl;
    }

};

int main() {
    Stack s;
    int n, input_value;
    int choice;

    while(true) {
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Check if the stack is empty or not" << endl;
        cout << "4. Check if the stack is full or not" << endl;
        cout << "5. Get the top element" << endl;
        cout << "6. Search an element in the stack" << endl;
        cout << "7. Exit the program" << endl;
        
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // push operation
                cout << "How many values do you want to insert into stack: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    cout << "Enter value " << i+1 << " : ";
                    cin >> input_value;
                    s.push(input_value);
                }

                // display the stack
                cout << endl << "Stack elements are --------------------------" << endl << endl;
                cout << "*****************************************************" << endl;
                s.display();
                cout << "*****************************************************" << endl;
                cout << endl << endl;

                break;

            case 2:
                s.pop();

                // display the stack
                cout << endl << "Stack elements are --------------------------" << endl << endl;
                cout << "*****************************************************" << endl;
                s.display();
                cout << "*****************************************************" << endl;
                cout << endl << endl;

                break;

            case 3:
                if(s.isEmpty()) {
                    cout << endl << "Stack is empty!" << endl << endl;
                } else {
                    cout << endl << "Stack is not empty!" << endl << endl;
                }
                break;

            case 4:
                if(s.isFull()) {
                    cout << endl << "Stack is full!" << endl << endl;
                } else {
                    cout << endl << "Stack is not full!" << endl << endl;
                }
                break;

            case 5:
                if(s.isEmpty()) {
                    cout << endl << "Stack Underflow!" << endl << endl;
                    break;
                }
                cout << endl << "Top element of the stack is: " << s.getTop() << endl << endl;
                break;

            case 7:
                exit(0);

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}