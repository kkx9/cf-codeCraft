#include<bits/stdc++.h>
using namespace std;

/*
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(2 * k);
        for (int i = 0; i < 2 * k; i += 2) {
            dp[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], -prices[i]);
            for (int j = 1; j < 2 * k; j++) {
                if (j % 2 == 0) {
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                } else {
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
            }
        }
        return dp[2 * k - 1];
    }
};