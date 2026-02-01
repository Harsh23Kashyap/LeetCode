class Solution {
public:
int pass(int i, vector<int>& nums, vector<int>& dp){
    if(i>=nums.size()-1)
    {
        return 0;

    }

    if(dp[i]!=-1)
    return dp[i];
    int mini=1e9;
    // cout<<nums[i]<<endl;
    for(int k=1;k<=nums[i];k++){
        mini=min(mini,1+pass(i+k,nums,dp));
    }
    return dp[i]=mini;

}
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
       
        return pass(0,nums,dp);
    }
};