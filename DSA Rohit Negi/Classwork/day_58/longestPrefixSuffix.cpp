#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestPrefixSuffix(string s) {
    int first = 0, second = s.size()-1;
    int current = 1, lps = 0;
    while(current < s.size()) {
        string str1, str2;
        if(s[first] == s[second]) {
            while(second < s.size()) {
                str1.push_back(s[first]);
                str2.push_back(s[second]);
                first++;
                second++;
            }
            if(str1 == str2) {
                lps = current;
            }
        }
        second = s.size();
        current++;
        first = 0;
        second -= current;
    }
    return lps;
}

int main() {
    string s = "ABCDEABCD";
    // string s = "ABCDABCEFABCD";
    // string s = "AACAA";
    cout << longestPrefixSuffix(s);
    return 0;
}