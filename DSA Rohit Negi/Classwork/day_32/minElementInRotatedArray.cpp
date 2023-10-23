#include <iostream>
#include <vector>
using namespace std;

int minElement(vector<int> &arr) {
    int start = 0, end = arr.size()-1;
    int mid, ans = -1;

    while(start <= end) {
        mid = start + (end - start) / 2;

        if(arr[0] < arr[mid]) {
            start = mid + 1;
        } else {
            ans = arr[mid];
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr {3, 4, 5, 10, 2};
    cout << minElement(arr) << endl;
    return 0;
}