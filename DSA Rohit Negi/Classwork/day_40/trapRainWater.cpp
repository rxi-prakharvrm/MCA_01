#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// My method 0(n^2)
int trapRainWater(vector<int> &arr, int n) {
    int waterTrapped = 0;
    int leftTallestBuilding = 0;
    int rightTallestBuilding = 0;

    for(int i = 1; i < n-1; i++) {
        // finding left tallest building
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] > leftTallestBuilding) {
                leftTallestBuilding = arr[j];
            }
        }

        // finding right tallest building
        for(int j = i+1; j < n; j++) {
            if(arr[j] > rightTallestBuilding) {
                rightTallestBuilding = arr[j];
            }
        }

        // Calculate trapped water
        if(arr[i] > leftTallestBuilding || arr[i] > rightTallestBuilding) {
            waterTrapped += 0;
        } else {
            waterTrapped += min(leftTallestBuilding, rightTallestBuilding) - arr[i];
        }

        leftTallestBuilding = 0;
        rightTallestBuilding = 0;
    }
    return waterTrapped;
}

int main() {
    vector<int> arr = {4, 2, 0, 5, 2, 6, 2, 3};
    int n = arr.size();
    int waterTrapped = trapRainWater(arr, n);
    cout << "Total units of water trapped in between the buildings: " << waterTrapped << endl;
    return 0;
}