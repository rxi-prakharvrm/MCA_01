#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findSubString(string str) {
        vector<int> count(256, 0);
        unordered_set<char> uniqueChars;
        int first = 0, second = 0, len = INT_MAX;

        // find the smallest window length that contains all the characters of a given string at least one time
        while (second < str.size()) {
            if (uniqueChars.size() < 256) {
                uniqueChars.insert(str[second]);
                count[str[second]]++;
                second++;
            } else {
                len = min(len, second - first);

                if (count[str[first]] > 1) {
                    count[str[first]]--;
                    first++;
                } else {
                    uniqueChars.erase(str[first]);
                    count[str[first]]--;
                    first++;
                }
            }
        }

        // Check for the remaining characters at the end of the string
        while (uniqueChars.size() == 256) {
            len = min(len, second - first);

            if (count[str[first]] > 1) {
                count[str[first]]--;
                first++;
            } else {
                uniqueChars.erase(str[first]);
                count[str[first]]--;
                first++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    string str = "AABBBCBBAC";
    Solution s;
    cout << s.findSubString(str) << endl;
    return 0;
}
