class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        if(nums.size()<3)
            return 0;
        vector<int> dp(nums.size(),0);
        int curr=nums[1]-nums[0];
        if(curr==nums[2]-nums[1])
            dp[2]=1;
        else
            curr=nums[2]-nums[1];
        
        
        for(int i=2;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]==curr)
            {
                dp[i+1]=dp[i]+1;
            }
            else
            {
                curr=nums[i+1]-nums[i];
            }
        }
        
        return accumulate(dp.begin(),dp.end(),0);
        
    }
};