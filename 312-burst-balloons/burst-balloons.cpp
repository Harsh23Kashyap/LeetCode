class Solution {
public:
    int pass(int l, int r, vector<vector<int>> &dp,vector<int>& nums  ){
        if(l>r)
            return 1;
        if(r>=nums.size())
        return 1;

        if(l<0)
        return 1;

        if(dp[l][r]!=-1)
        return dp[l][r];
        int res=0;
        for(int k=l+1;k<r;k++){
            int ans=nums[l]*nums[r]*nums[k]+pass(l,k,dp,nums)+pass(k,r,dp,nums);
            res=max(res,ans);
        }

        return dp[l][r]=res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),-1));
        return pass(0,nums.size()-1,dp,nums);

    }
};