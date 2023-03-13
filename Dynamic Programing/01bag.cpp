#include<bits/stdc++.h>
using namespace std;

// 一维dp数组
int zeroOneBag1(int capacity, vector<int> weight, vector<int> value) {
    int m = weight.size();
    vector<int> dp(capacity + 1);
    for (int i = 0; i < m; i++) {
        for (int j = capacity; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[capacity];
}

// 二维dp数组
int zeroOneBag2(int capacity, vector<int> weight, vector<int> value) {
    int m = weight.size();
    vector<vector<int>> dp(m, vector<int>(capacity + 1));
    // 初始化
    for (int j = 1; j <= capacity; j++) {
        if (j >= weight[0]) {
            dp[0][j] = value[0];
        }
    }
    // 求解dp数组
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    return dp[m - 1][capacity];
}

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int capacity = 4;
    int ans1 = zeroOneBag1(capacity, weight, value);
    int ans2 = zeroOneBag2(capacity, weight, value);
    cout << ans1 << ' ' << ans2;
    return 0;
}