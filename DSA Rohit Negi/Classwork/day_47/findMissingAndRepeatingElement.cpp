#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(N) , Space Complexity = O(1) ====================================================
void findMissingAndRepeating(vector<int> &arr, int n) {
    int repeating, missing, pos;

    // decrease each and every element of array by 1
    for(int i = 0; i < n; i++) {
        arr[i]--;
    }

    // modifying this array in the way where each element place will store two values logically
    // one for the original number and the other one is the number of occurrence of that number
    for(int i = 0; i < n; i++) {
        pos = arr[i] % n;
        arr[pos] += n;
    }

    // printing the repeating values of the array
    for(int i = 0; i < n; i++) {
        if(arr[i] / n == 2) {
            cout << "Repeating value is: " << i + 1 << endl;
            break;
        }
    }

    // printing the missing value of the array
    for(int i = 0; i < n; i++) {
        if(arr[i] / n == 0) {
            cout << "Missing value is: " << i + 1 << endl;
            break;
        }
    }
}



// Time complexity = O(N) , Space complexity = O(N) ====================================================

// void findMissingAndRepeating(vector<int> &arr, int n) {    
//     vector<int> newArr(7, 0); // Extra space of size N
//     int repeating;
//     int missing;

//     for(int i = 0; i < n; i++) {
//         newArr[arr[i]-1] += 1;
//     }

//     for(int i = 0; i < newArr.size(); i++) {
//         if(newArr[i] > 1) {
//             repeating = i+1;
//             break;
//         }
//     }

//     for(int i = 0; i < newArr.size(); i++) {        
//         if(newArr[i] == 0) {
//             missing = i+1;
//             break;
//         }
//     }

//     cout << repeating << endl << missing << endl;
// }

int main() {
    vector<int> arr = {4, 2, 6, 1, 7, 3, 10, 8, 9, 10};
    int n = arr.size();
    findMissingAndRepeating(arr, n);
    return 0;
}