class Solution {
public:
    bool pass(vector<int>& nums, vector<int> &dp,int i)
    {
        
        if(i==nums.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        
        bool ans=false;
        if(i+2<nums.size() and nums[i]==nums[i+1] and nums[i+1]==nums[i+2] )
            ans=ans|pass(nums,dp,i+3);
        if(i+2<nums.size() and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1 )
            ans=ans|pass(nums,dp,i+3);
        if(i+1<nums.size() and nums[i+1]==nums[i])
            ans=ans|pass(nums,dp,i+2);
        
        return dp[i]=ans;
        
    }
    bool validPartition(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1,-1);
        
        bool f= pass(nums,dp,0);
        for(int i=0;i<nums.size()+1;i++)
            cout<<dp[i]<<" ";
        return f;
    }
};