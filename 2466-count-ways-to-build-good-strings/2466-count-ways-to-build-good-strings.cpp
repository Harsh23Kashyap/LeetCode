#define ll long long 
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int m=1e9+7;
        if(high==0)
            return 1;
        vector<ll> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0)
                dp[i]+=dp[i-zero]%m;
            if(i-one>=0)
                dp[i]+=dp[i-one]%m;
            
            
        }
        ll ans=0;
        for(int i=low;i<=high;i++)
        {
            ans+=dp[i];
        }
        return ans%m;
    }
};