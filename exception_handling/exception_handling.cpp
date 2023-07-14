#include <iostream>
using namespace std;

int main() {
    try{
        int age = 17;
        if(age < 18) {
            throw(age);
        }
    }
    catch(int myNum) {
        cout << "Your current age is: " << myNum << " that is below 18. So you aren't eligible for this event.";
    }
    return 0;
}
