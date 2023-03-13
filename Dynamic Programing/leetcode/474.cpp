#include<bits/stdc++.h>
using namespace std;

/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<int> zeros(k);
        vector<int> ones(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    zeros[i]++;
                } else {
                    ones[i]++;
                }
            }
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < k; i++) {
            for (int r = m; r >= zeros[i]; r--) {
                for (int c = n; c >= ones[i]; c--) {
                    dp[r][c] = max(dp[r][c], dp[r - zeros[i]][c - ones[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5; 
    int n = 3;
    Solution solution;
    cout << solution.findMaxForm(strs, m, n);
    return 0;
}