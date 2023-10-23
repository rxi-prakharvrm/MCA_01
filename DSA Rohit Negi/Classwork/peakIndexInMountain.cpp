#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = n-1;
    int mid, ans = -1;

    while(start <= end) {
        mid = end + (start - end) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            ans = mid;
            cout << ans << endl;
            exit(0);
        } else if(arr[mid] < arr[mid-1]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return 0;
}