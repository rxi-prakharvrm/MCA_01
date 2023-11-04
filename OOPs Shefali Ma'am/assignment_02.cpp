#include <iostream>
#include <string>
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
    void selectionSort(int arr[], int n) {
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    // insertion sort
    // bubble sort
    // merge sort
    // quick sort
};

// Que: 3. Number of occurrence of each number in sorted array
void occurrencesInSortedArray() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int presentElement = arr[0];
    int occurrenceCounter = 1;

    for(int i = 1; i <= n; i++) {
        if(arr[i] == presentElement) {
            occurrenceCounter++;
        } else {
            presentElement = arr[i];
            cout << occurrenceCounter << " ";
            occurrenceCounter = 1;
        }
    }
}

// Que: 4. Find third largest string in an array of strings
string longestStringInArray(string animals[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(animals[i].size() < animals[j].size()) {
                swap(animals[i], animals[j]);
            }
        }
    }

    return animals[2];
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
    // smallest element in array ===================================================
    cout << smallestElementInArray() << endl;

    // selection sort ==============================================================
    int arr[] = {6, 2, 4, 5, 8, 8, 9, 9, 3, 0, 0, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Sort s;
    s.selectionSort(arr, n);

    // Number of occurrence of each element in array ===============================
    occurrencesInSortedArray();

    // longest size string in the array of strings =================================
    string animals[] = {"Zebra", "Elephant", "Hippopotomus", "Lion", "Pegion", "Ant"};
    int n = sizeof(animals) / sizeof(animals[0]);
    cout << "Longest string is: " << longestStringInArray(animals, n) << endl;

    // Product and Sum of the element of an array ==================================
    // productAndSum PS;
    // cout << "Product of elements of the array is: " << PS.product() << endl;
    // cout << "Sum of elements of the array is: " << PS.sum() << endl;

    // Reverse the string in an array of strings ===================================
    // string animals[] = {"Zebra", "Elephant", "Hippopotomus", "Lion"};
    // int n = sizeof(animals) / sizeof(animals[0]);
    // reverseStringInArray(animals, n);

    // for(int i = 0; i < n; i++) {
    //     cout << animals[i] << " ";
    // }

    // Duplicate Elements in array =================================================
    // int arr[] = {6, 2, 4, 5, 8, 8, 9, 9, 3, 0, 0, 1, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // duplicateElementsInArray(arr, n);

    // Reverse a string
    // string str = "Encapsulation";
    // reverseString(str, 0, str.size()-1);
    // cout << str << endl;

    return 0;
}