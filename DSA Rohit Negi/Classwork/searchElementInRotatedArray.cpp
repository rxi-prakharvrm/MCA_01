#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid, ans = -1;

        while(start <= end) {
            mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                ans = mid;
            }

            if(nums[mid] >= nums[0]) {
                if(target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if(target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr {3, 5, 6, 0, 1, 2};
    Solution s;
    cout << s.search(arr, 1);
    return 0;
}