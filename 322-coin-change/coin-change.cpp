class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int t=0;
        sort(coins.begin(),coins.end());
        // if(coins[0]>amount)
        //     return -1;
        vector<int> dp(amount+1,-1);
        if(amount==0)
        return 0;
        if(coins[0]>amount)
        return -1;
        dp[coins[0]]=1;
        for(int i=coins[0]+1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++){
                if(i==coins[j]){
                    dp[i]=1;
                    break;
                }
                if(i-coins[j]<0)
                    break;
                
                if(dp[i-coins[j]]!=-1)
                {
                    if(dp[i]==-1)
                        dp[i]=dp[i-coins[j]]+1;
                    else
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount];

    }
};