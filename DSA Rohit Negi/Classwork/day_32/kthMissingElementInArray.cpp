#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int kthMissingElement(vector<int> &arr, int k) {
        int start = 0, end = arr.size()-1;
        int mid, index, ans;

        while(start <= end) {
            mid = start + (end - start) / 2;

            if(arr[mid]-mid-1 >= k) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        ans = index + k;
        return ans;
    }
};

int main() {
    vector<int> arr {2, 3, 4, 7, 11};
    int k = 5;
    Solution s;
    cout << s.kthMissingElement(arr, k);
    return 0;
}