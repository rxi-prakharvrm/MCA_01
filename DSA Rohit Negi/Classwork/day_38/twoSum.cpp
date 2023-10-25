#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int n, int target) {
    vector<int> ans;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                return ans;
            }
        }
    }
    // return ans;
}

int main() {
    vector<int> arr = {2, 7, 11, 15, 27};
    int target = 29;
    vector<int> ans = twoSum(arr, arr.size(), target);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}