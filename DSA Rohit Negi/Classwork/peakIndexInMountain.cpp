#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 4, 5, 10, 11, 12, 13, 20, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = n-1;
    int mid, ans = 0;

    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] > arr[0]) {
            ans = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}