class Solution {
public:
int maxi(vector<int> &nums, int l, int r, vector<vector<int>> &dp){
    if(l>r)
        return 0;
    if(dp[l][r]!=-1)
    return dp[l][r];
dp[l][r] = 0; 

    for (int i = l + 1; i < r; ++i) {
    int coins = nums[l] * nums[i] * nums[r] + maxi(nums, l, i, dp) + maxi(nums, i, r, dp);
    dp[l][r] = max(dp[l][r], coins);
}

    return dp[l][r];
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return maxi(nums,0,nums.size()-1,dp);
    }
};