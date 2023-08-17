#include<bits/stdc++.h>
using namespace std;

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

/*
题解：
1. 确定dp数组。dp[i][0]表示第i天“持有”股票时的最大金额，dp[i][1]表示第i天不“持有”股票时的最大金额
2. 确定递推公式。
    a. 第i天“持有”股票，dp[i][0]可以由两种状态推出
        * 第i - 1天持有股票，则保持股票继续持有，dp[i][0] = dp[i - 1][0]
        * 第i天买入股票，dp[i][0] = -prices[i]
        * 所以，dp[i][0] = max(dp[i - 1][0], -prices[i])
    b. 第i天不“持有”股票，dp[i][1]可以由两种状态推出
        * 第i - 1天就不持有股票，保持现状，dp[i][1] = dp[i - 1][1]
        * 第i天卖出股票，dp[i][1] = prices[i] + dp[i - 1][0]
        * 所以，dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0])
3. 初始化。
    * dp[0][0]表示第0天持有股票，此时的持有股票就一定是买入股票了，所以dp[0][0] -= prices[0]
    * dp[0][1]表示第0天不持有股票，不持有股票那么现金就是0，所以dp[0][1] = 0
4. 确定遍历顺序。
    从递推公式可以看出dp[i]都是由dp[i - 1]推导出来的，那么一定是从前向后遍历。
5. 举例推导dp数组。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[m - 1][1];
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    cout << solution.maxProfit(prices);
    return 0;
}