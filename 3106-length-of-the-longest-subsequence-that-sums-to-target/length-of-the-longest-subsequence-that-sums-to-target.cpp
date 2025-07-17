class Solution {
public:
    int pass(vector<int>& nums, int target, int i, vector<vector<int>> &dp) {
        if (target == 0) return 0;
        if (target < 0 || i >= nums.size()) return -1;

        if (dp[i][target] != -2)
            return dp[i][target];

        int include = pass(nums, target - nums[i], i + 1, dp);
        int exclude = pass(nums, target, i + 1, dp);

        int res = -1;
        if (include != -1) res = max(res, include + 1);
        if (exclude != -1) res = max(res, exclude);

        return dp[i][target] = res;
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -2));
        int ans = pass(nums, target, 0, dp);
        return ans;
    }
};
