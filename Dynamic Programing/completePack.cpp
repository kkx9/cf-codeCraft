#include<bits/stdc++.h>
using namespace std;

int completePack(vector<int> weight, vector<int> value, int capacity) {
    vector<int> dp(capacity + 1);
    int m = weight.size();
    for (int i = 0; i < m; i++) {
        for (int j = weight[i]; j <= capacity; j++) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[capacity];
}

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int capacity = 4;
    int ans = completePack(weight, value, capacity);
    cout << ans;
    return 0;
}