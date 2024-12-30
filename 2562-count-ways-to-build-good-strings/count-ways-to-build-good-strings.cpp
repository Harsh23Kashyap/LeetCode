class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int m=1e9+7;
        vector<long long> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++)
        {
            if(i>=zero)
                dp[i]=(dp[i]+dp[i-zero])%m;

            if(i>=one)
                dp[i]=(dp[i]+dp[i-one])%m;

        }

        long long ans=0;
        for(int i=low;i<=high;i++)
        {
            ans= (ans+dp[i])%m;
        }
        return ans;
        
    }
};