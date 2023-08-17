#include<bits/stdc++.h>
using namespace std;

/*
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

/*
与121题唯一的区别就在于递推公式上，第i天持有股票时，如果是第i天买入股票，那么金额会受到前面买股票获得的利润影响。
即dp[i][0] = dp[i - 1][1] - prices[i]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[m - 1][1];
    }
};