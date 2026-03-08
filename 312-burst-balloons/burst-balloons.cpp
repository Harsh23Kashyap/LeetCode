class Solution {
public:
int pss(int l, int r, vector<int>& nums, vector<vector<int>> &dp){
    if(r>=nums.size())
        return 1;
    if(l<0)
    return 1;

    if(dp[l][r]!=-1)
    return dp[l][r];
    int ans=0;
    for(int k=l+1;k<r;k++){
        int curr=pss(l,k,nums,dp)+pss(k,r,nums,dp)+nums[l]*nums[r]*nums[k];
        ans=max(ans,curr);
    }
    return dp[l][r]=ans;
}

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),-1));
        return pss(0,nums.size()-1, nums,dp);
    }
};