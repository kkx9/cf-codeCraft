#include<bits/stdc++.h>
using namespace std;

/*
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum < abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }
        int capacity = (sum + target) / 2;
        vector<int> dp(capacity + 1);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = capacity; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
};

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    Solution solution;
    cout << solution.findTargetSumWays(nums, target);
    return 0;
}