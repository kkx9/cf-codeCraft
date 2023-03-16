#include<bits/stdc++.h>
using namespace std;

/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    Solution solution;
    cout << solution.coinChange(coins, amount);
    return 0;
}