#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void intersection(vector<int> arr1, vector<int> arr2, vector<int> &ans) {

    // push common elements in ans array
    for(int i = 0; i < arr1.size(); i++) {
        for(int j = 0; j < arr2.size(); j++) {
            if(arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]); 
                break;
            }
        }
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
    vector<int> arr1 = {1, 2, 2, 3, 5, 6, 7};
    vector<int> arr2 = {2, 2, 3, 7, 6};
    vector<int> ans;

    intersection(arr1, arr2, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}