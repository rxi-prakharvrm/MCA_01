#include <iostream>
#include <climits>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Que: 1. Find the smallest element in array
int smallestElementInArray() {
    int arr[] = {6, 12, 8, 41, 5};
    int n = sizeof(arr) / sizeof(arr[0]);    
    int min = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] < min) min = arr[i];
    }

    return min;
}

// Que: 2. Sort an array
class Sort {
    public:

    // selection sort
    // insertion sort
    // bubble sort
    // merge sort
    // quick sort
};

// Que: 3. Number of occurrence of each number in sorted array
vector<int> occurrencesInSortedArray() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> occurrenceArray;
    int presentElement = arr[0];
    int occurrenceCounter = 1;

    for(int i = 1; i <= n; i++) {
        if(arr[i] == presentElement) {
            occurrenceCounter++;
        } else {
            presentElement = arr[i];
            occurrenceArray.push_back(occurrenceCounter);
            occurrenceCounter = 1;
        }
    }

    return occurrenceArray;
}

// Que: 4. Find third largest string in an array of strings
int longestStringInArray() {
    string animals[] = {"Zebra", "Elephant", "Hippopotomus", "Lion"};
    int n = sizeof(animals) / sizeof(animals[0]);
    int longestStringSize = 0;

    for(int i = 0; i < n; i++) {
        if(animals[i].size() > longestStringSize) {
            longestStringSize = animals[i].size();
        }
    }

    return longestStringSize;
}

// Que: 5. Product and Sum of element in array
class productAndSum {
    public:
    int arr[4] = {1, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[1]);

    int product() {
        int product = 1;

        for(int i = 0; i < n; i++) {
            product *= arr[i];
        }

        return product;
    }

    int sum() {
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }

        return sum;
    }
};

// Que: 6. Reverse string in an array of strings
void reverseStringInArray(string arr[], int n) {
    int start;
    int end;

    for(int i = 0; i < n; i++) {
        start = 0;
        end = arr[i].size()-1;

        while(start < end) {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}

// Que: 7. Find duplication in array
void duplicateElementsInArray(int arr[], int n) {
    int duplicateElement;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                duplicateElement = arr[i];
                cout << duplicateElement << " ";
                break;
            }
        }
    }
}

// Que: 8. Reverse a string
void reverseString(string &str, int start, int end) {
    if(start >= end) return;
    swap(str[start], str[end]);
    return reverseString(str, start + 1, end - 1);
}


int main() {
    // smallest element in array ================================================================
    // cout << smallestElementInArray() << endl;

    // Number of occurrence of each element in array ============================================
    // vector<int> occurrenceArray = occurrencesInSortedArray();
    // for(int i = 0; i < occurrenceArray.size(); i++) {
    //     cout << occurrenceArray[i] << " ";
    // }

    // longest size string in the array of strings ==============================================
    // cout << "Longest string is of length: " << longestStringInArray() << endl;

    // Product and Sum of the element of an array ===============================================
    // productAndSum PS;
    // cout << "Product of elements of the array is: " << PS.product() << endl;
    // cout << "Sum of elements of the array is: " << PS.sum() << endl;

    // Reverse the string in an array of strings ================================================
    // string animals[] = {"Zebra", "Elephant", "Hippopotomus", "Lion"};
    // int n = sizeof(animals) / sizeof(animals[0]);
    // reverseStringInArray(animals, n);

    // for(int i = 0; i < n; i++) {
    //     cout << animals[i] << " ";
    // }

    // Duplicate Elements in array ==============================================================
    // int arr[] = {6, 2, 4, 5, 8, 8, 9, 9, 3, 0, 0, 1, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // duplicateElementsInArray(arr, n);

    // Reverse a string
    string str = "Encapsulation";
    reverseString(str, 0, str.size()-1);
    cout << str << endl;

    return 0;
}