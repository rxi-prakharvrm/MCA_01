#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int n, int target) {
    vector<int> ans;

    // O(n^2)
    // for(int i = 0; i < n-1; i++) {
    //     for(int j = i+1; j < n; j++) {
    //         if(arr[i] + arr[j] == target) {
    //             ans.push_back(arr[i]);
    //             ans.push_back(arr[j]);
    //             return ans;
    //         }
    //     }
    // }


    // nlog(n)
    // int x, start, end, mid;
    // for(int i = 0; i < n-1; i++) {
    //     x = target - arr[i];
    //     start = i+1;
    //     end = n-1;

    //     while(start <= end) {
    //         mid = start + (end - start) / 2;
    //         if(x == arr[mid]) {
    //             return {arr[i], arr[mid]};
    //         }
    //         if(x < arr[mid]) {
    //             end = mid - 1;
    //         } else {
    //             start = mid + 1;
    //         }
    //     }
    // }

    // O(n)
    int start = 0;
    int end = arr.size() - 1;

    while(start < end) {
        if(arr[start] + arr[end] == target) {
            ans.push_back(arr[start]);
            ans.push_back(arr[end]);
            return ans;
        }

        if(arr[start] + arr[end] < target) {
            start++;
        } else {
            end--;
        }
    }
}

int main() {
    vector<int> arr = {2, 7, 11, 15, 27};
    int target = 22;
    vector<int> ans = twoSum(arr, arr.size(), target);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}