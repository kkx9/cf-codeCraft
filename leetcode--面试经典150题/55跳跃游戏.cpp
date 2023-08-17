#include<bits/stdc++.h>
using namespace std;

/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/

/*
示例 1：

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
*/

/*
题解：贪心
维护最远可达到位置变量farthest。从下标0开始遍历，不断更新farthest，若 farthest ≥ 最后一个下标，则返回true；否则返回false
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i <= farthest) {
                farthest = max(farthest, i + nums[i]);
                if (farthest >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution solution;
    cout << solution.canJump(nums);
    return 0;
}