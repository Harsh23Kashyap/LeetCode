class Solution {
public:
    int dfs(int i, vector<int>& prices, vector<vector<vector<int>>> &dp, int used, int bought){
        if(used>=2)
            return 0;
        if(i==prices.size())
        return 0;

        if(dp[i][used][bought]!=INT_MAX){
            return dp[i][used][bought];
        }
        int res=0;
        //if bough already
        if(bought!=0){
            //either sell if profitable
                res=max(res,prices[i]+dfs(i+1,prices,dp,used+1,0));
            //or hold
            res=max(res,dfs(i+1,prices,dp,used,bought));
        }
        //if not bought
        else{
        //buy today

        res=max(res,-prices[i]+dfs(i+1,prices,dp,used,1));


        //or just move on
        res=max(res,dfs(i+1,prices,dp,used,bought));
        }


        return dp[i][used][bought]=res;
    }   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3,vector<int> (2,INT_MAX)));
        // vector<vector<int>> dp(n, vector<int> (2,INT_MAX));
        return dfs(0,prices,dp,0,0);
    }
};