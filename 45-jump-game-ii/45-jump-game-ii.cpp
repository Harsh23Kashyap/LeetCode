class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int steps=0;
        vector<int> dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size() and j<i+nums[i]+1;j++)
            {
                dp[j]=min(dp[j],1+dp[i]);
            }
        }
        return dp[dp.size()-1];
    }
};