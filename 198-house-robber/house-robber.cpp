class Solution {
public:
    int rob(vector<int> nums, int i,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int current=0;
        for(int j=i;j<nums.size();j++){
            current=max(nums[j]+rob(nums,j+2,dp),current);
        }
        return dp[i]=current;

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int maxi=0;
        rob(nums,0,dp);
        return dp[0];
    }
};