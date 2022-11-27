class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        if(nums.size()<3)
            return 0;
        
        int n=nums.size();
        vector<int> dp(n,0);
        int curr=nums[1]-nums[0];
        if(curr==nums[2]-nums[1])
            dp[2]=1;
        //int maxi=max(0,dp[2]);
        
        for(int i=2;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]==curr)
            {
                dp[i+1]=dp[i]+1;
                //maxi=max(maxi,dp[i]);
            }
            curr=nums[i+1]-nums[i];
            
        }
        return accumulate(dp.begin(),dp.end(),0);
        
    }
};