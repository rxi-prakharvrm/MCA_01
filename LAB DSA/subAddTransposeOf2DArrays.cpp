#include <iostream>
using namespace std;

const int m = 2;
const int n = 3;

// print the resulted array
void printArray(int new_arr[m][n]) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < 3; j++) {
      cout << new_arr[i][j] << " ";
    }
    cout << endl;
  }
}

// summation of the array
void summationOfArray(int arr1[m][n], int arr2[m][n]) {
  int sum[m][n];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      sum[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  printArray(sum);
}

// subtraction of the array
void subtractionOfArray(int arr1[m][n], int arr2[m][n]) {
  int sub[m][n];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      sub[i][j] = arr1[i][j] - arr2[i][j];
    }
  }
  printArray(sub);
}

// Transpose of an array
void transposeOfArray(int arr[m][n]) {
  int transArray[n][m];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      transArray[j][i] = arr[i][j];
    }
  }

  // printing transposed array
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << transArray[i][j] << " ";
    }
    cout << endl;
  }
}

// Main function
int main() {
  int choice;
  int arr1[m][n] = {{12, 1, 4}, {21, 55, 2}};
  int arr2[m][n] = {{5, 8, 9}, {1, 5, 11}};

  while(true) {
    cout << "1. Summation of arrays" << endl;
    cout << "2. Subtraction of arrays" << endl;
    cout << "3. Transpose of array" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
      case 1:
        cout << "Array-1: " << endl;
        printArray(arr1);
        cout << endl;
        cout << "Array-2: " << endl;
        printArray(arr2);
        cout << endl;
        cout << "Summation: " << endl;
        summationOfArray(arr1, arr2);
        cout << endl;
        break;

      case 2:
        cout << "Array-1: " << endl;
        printArray(arr1);
        cout << endl;
        cout << "Array-2: " << endl;
        printArray(arr2);
        cout << endl;
        cout << "Subtraction: " << endl;
        subtractionOfArray(arr1, arr2);
        cout << endl;
        break;

      case 3:
        cout << "Array: " << endl;
        printArray(arr1);
        cout << endl;
        cout << "Transpose: " << endl;
        transposeOfArray(arr1);
        cout << endl;
        break;

      case 4:
        exit(0);

      default:
        cout << "Invalid choice! Try again" << endl;
        exit(0);
    }
  }
  
  return 0;
}