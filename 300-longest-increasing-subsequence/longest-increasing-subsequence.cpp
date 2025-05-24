class Solution {
public:
    int solve(int i, int prev_index, vector<int>& nums, vector<vector<int>>& memo) {
        if (i == nums.size()) return 0;
        
        if (memo[i][prev_index + 1] != -1)
            return memo[i][prev_index + 1];
        
        // Choice 1: Skip current element
        int notTake = solve(i + 1, prev_index, nums, memo);
        
        // Choice 2: Take current element (if increasing)
        int take = 0;
        if (prev_index == -1 || nums[i] > nums[prev_index]) {
            take = 1 + solve(i + 1, i, nums, memo);
        }
        
        return memo[i][prev_index + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // prev_index goes from -1 to n-1 → so total size is (n+1)
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, memo);
    }
};
