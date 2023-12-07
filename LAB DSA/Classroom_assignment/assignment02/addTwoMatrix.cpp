#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> addTwoMatrix(vector<vector<int>> m1, vector<vector<int>> m2) {
    int rows = m1.size();
    int cols = m1[0].size();

    vector<vector<int>> ans(rows, vector<int>(cols, 0));

    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1[0].size(); j++) {
            ans[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> m1 = {{1, 1, 1}, {0, 0, 0}};
    vector<vector<int>> m2 = {{1, 1, 1}, {3, 3, 3}};
    vector<vector<int>> res = addTwoMatrix(m1, m2);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}