class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        if(sum%2!=0)
            return false;
        int k=sum/2;
        
        vector<vector<bool>> dp(nums.size(),vector<bool> (k+1,false));
        
        for(int i=0;i<nums.size();i++)
            dp[i][0]=true;
        
        if(nums[0]<=k)
            dp[0][nums[0]]=true;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=k;j++)
            {
                //cout<<i<<" "<<j<<endl;
                bool notTaken=dp[i-1][j];
                if(nums[i]<=j)
                    notTaken|=dp[i-1][j-nums[i]];
                
                dp[i][j]=notTaken;
            }
            
        }
        return dp[nums.size()-1][k];
        
        
    }
};