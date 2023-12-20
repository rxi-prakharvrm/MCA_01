#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Returning a union set
void unionOfArrayElements(vector<int> arr1, vector<int> arr2, vector<int> &ans) {

    // store all the unique elements in ans from arr1
    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr2.size(); j++) {
            ans.push_back(arr1[i]);
            if(arr1[i] == arr2[j]) {
                arr2.erase(arr2.begin()+j);
            }
        }
    }

    // insert remaining elements of arr2 in ans
    for(int i = 0; i < arr2.size(); i++) {
        ans.push_back(arr2[i]);
    }
    
    // store -1 at the place of a number occurred more than once
    for (int i = 0; i < ans.size() - 1; i++) {
        for(int j = i+1; j < ans.size(); j++) {
            if(ans[i] == ans[j]) {
                ans[i] = -1; 
            }
        }
    }

    // remove all the occurrences of -1 and reduce the size of the ans array accordingly
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == -1) {
            ans.erase(ans.begin()+i);
            i--;
        }
    }
}

int main() {
    vector<int> arr1 = {1, 2, 2, 7, 3};
    vector<int> arr2 = {2, 2, 3, 9, 15};
    vector<int> ans;

    unionOfArrayElements(arr1, arr2, ans);

    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}