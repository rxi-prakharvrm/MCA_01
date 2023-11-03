#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Worst time complexity = O(n + m)
// Best time complexity = O(1)
bool search(vector<vector<int> > matrix, int n, int m, int x) {
    // code here 
    int i = 0;
    int j = n-1;
    while(i < n && j >= 0) {
        if(matrix[i][j] == x) return 1;
        else if(matrix[i][j] > x) j--;
        else i++;
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix = 
    {
        {4, 8, 15, 25, 60},
        {18, 22, 26, 42, 80},
        {36, 40, 45, 68, 104},
        {48, 50, 72, 83, 130},
        {70, 99, 114, 128, 170}
    };
    
    int row = 5, col = 5, target;
    cout << "Enter the number you want to search: ";
    cin >> target;

    cout << search(matrix, row, col, target) << endl;
    return 0;
}