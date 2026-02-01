class Solution {
public:
int maxi=0;
int n;
    int dps(int i, int bought, int ck, vector<vector<vector<int>>> &dp,vector<int>& prices ){
        if(i==n)
        return 0;
        if(ck==maxi)
        return 0;
        if(dp[i][ck][bought]!=INT_MAX)
            return dp[i][ck][bought];
        /* options i have are
        if already bought then sell today or just move on

        if not bought then just move on or buy tpday*/
        int res=0;
        if(bought){
            //sell
            res=max(res,prices[i]+dps(i+1,0,ck+1,dp,prices));

            //dot sell
            res=max(res,dps(i+1,1,ck,dp,prices));
        }
        else{
            //buy
            res=max(res,-prices[i]+dps(i+1,1,ck,dp,prices));

            //dont buy
            res=max(res,dps(i+1,0,ck,dp,prices));
        }

        return dp[i][ck][bought]=res;
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k, vector<int> (2,INT_MAX)));
        maxi=k;
        return dps(0,0,0,dp,prices);
    }
};