class Solution {
public:
    
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        return maxcoin(dp, 0, nums.size() - 1, nums);
    }
    int maxcoin(vector<vector<int>> &dp, int l, int r, vector<int>& nums)
    {
        if(r - l == 1) 
            return 0;
        if(dp[l][r] > 0)
            return dp[l][r];
        int ans = 0;
        for(int i = l + 1; i < r; ++i)
            ans = max(ans, nums[l] * nums[i] * nums[r] + maxcoin(dp, l, i, nums ) + maxcoin(dp, i, r, nums));

        dp[l][r] = ans;
        return ans;
    }
        
        
    
};