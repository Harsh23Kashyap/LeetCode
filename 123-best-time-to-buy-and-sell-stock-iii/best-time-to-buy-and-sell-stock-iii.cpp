class Solution {
public:
//st 1 is buy
//st 0 is not bought now
    int dfs(vector<int>& prices, int i, int st, int k,  vector<vector<vector<int>>> &dp){
        if(i==prices.size())
        return 0;
        if(dp[i][st][k]!=-1)
        return dp[i][st][k];
        int high=0;
        if(st==1){
            //i can hold;
            int hold=dfs(prices,i+1,st,k,dp);

            //i can sell;
            int sell=dfs(prices,i+1,0,k,dp)+prices[i];
            high=max(hold,sell);

        }
        else{
            // i can but if k>0
            int buy=0;
            if(k>0){
                buy=dfs(prices,i+1,1,k-1,dp)-prices[i];
            }
            //i can not buy and move
            int notbuy=dfs(prices,i+1,st,k,dp);
             high=max(buy,notbuy);
        }

        return dp[i][st][k]=high;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (3,-1))); 
        return dfs(prices, 0,0,2,dp);
    }
};