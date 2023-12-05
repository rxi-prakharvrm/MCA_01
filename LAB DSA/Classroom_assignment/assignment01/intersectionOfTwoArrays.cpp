#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> arr1, vector<int> arr2, vector<int> &ans) {
    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr2.size(); j++) {
            if(arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]);
                break;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 5, 6, 7};
    vector<int> arr2 = {2, 3, 7, 6};
    vector<int> ans;

    intersection(arr1, arr2, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}