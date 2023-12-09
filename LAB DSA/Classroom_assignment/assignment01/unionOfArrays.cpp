#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Returning a union set
set<int> unionOfArrayElements(vector<int> arr1, vector<int> arr2, set<int> &ans) {

    // store all the unique elements in ans from arr1
    for(int i = 0; i < arr1.size(); i++) {
        ans.insert(arr1[i]);
    }

    // store all the unique elements in ans from arr2
    for(int i = 0; i < arr2.size(); i++) {
        ans.insert(arr2[i]);
    }
    
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 7, 3};
    vector<int> arr2 = {2, 2, 3, 9, 15};
    set<int> ans;

    unionOfArrayElements(arr1, arr2, ans);

    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}