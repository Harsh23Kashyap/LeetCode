class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        
        int n=nums.size();
        vector<long long> dp(n,0);
        if(nums[0]==0)
            dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=0)
            {
                dp[i]=0;
            }
            else
            {
                //cout<<"runs"<<endl;
                dp[i]=dp[i-1]+1;
//                 if(nums[i-1]==0)
//                 {
//                     cout<<"run2s"<<endl;
                    
//                 }
            }
          // cout<<dp[i]<<" "<<endl;
            
        }
        long long a=0;
        for(int i:dp)
            a+=i;
            
        return a;
        
    }
};