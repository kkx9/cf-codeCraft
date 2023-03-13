#include<bits/stdc++.h>
using namespace std;

/* 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int capacity = sum / 2;
        vector<int> dp(capacity + 1);
        for (int i = 0; i < n; i++) {
            for (int j = capacity; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[capacity] == capacity) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    Solution solution;
    cout << solution.canPartition(nums);
    return 0;
}