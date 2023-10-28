#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ***************************** METHOD-01 (OWN) ******************************
// ++++++++++++++++++++++++++++++++ O(n^2) ++++++++++++++++++++++++++++++++

// int trapRainWater(vector<int> &arr, int n) {
//     int waterTrapped = 0;
//     int leftTallestBuilding = 0;
//     int rightTallestBuilding = 0;

//     for(int i = 1; i < n-1; i++) {
//         // finding left tallest building
//         for(int j = i-1; j >= 0; j--) {
//             if(arr[j] > leftTallestBuilding) {
//                 leftTallestBuilding = arr[j];
//             }
//         }

//         // finding right tallest building
//         for(int j = i+1; j < n; j++) {
//             if(arr[j] > rightTallestBuilding) {
//                 rightTallestBuilding = arr[j];
//             }
//         }

//         // Calculate trapped water
//         if(arr[i] > leftTallestBuilding || arr[i] > rightTallestBuilding) {
//             waterTrapped += 0;
//         } else {
//             waterTrapped += min(leftTallestBuilding, rightTallestBuilding) - arr[i];
//         }

//         leftTallestBuilding = 0;
//         rightTallestBuilding = 0;
//     }
//     return waterTrapped;
// }

// ***************************** METHOD-02 ******************************
// ++++++++++++++++++++++++++++++++ O(n) ++++++++++++++++++++++++++++++++
int trapRainWater(vector<int> &height, int n) {
    int leftMax = 0, rightMax = 0, maxHeight = height[0], index = 0, waterTrapped = 0;

    // Max height building
    for(int i = 1; i < n; i++) {
        if(maxHeight < height[i]) {
            maxHeight = height[i];
            index = i;
        }
    }

    // Left Part
    for(int i = 0; i < index; i++) {
        if(leftMax > height[i]) {
            waterTrapped += leftMax - height[i];
        } else {
            leftMax = height[i];
        }
    }

    // Right Part
    for(int i = n-1; i > index; i--) {
        if(rightMax > height[i]) {
            waterTrapped += rightMax - height[i];
        } else {
            rightMax = height[i];
        }
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