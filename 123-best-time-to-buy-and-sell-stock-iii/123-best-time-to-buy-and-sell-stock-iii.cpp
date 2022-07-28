class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recursion(vector<int>&prices,int pos,bool buy,int t)
    {
        if(pos>=prices.size() or t==0)
            return 0;
        
        if(dp[buy][t][pos]!=-1)
            return dp[buy][t][pos];
        //SKIP
        int curr=recursion(prices,pos+1,buy, t);
        //BUY
        if(buy)
        {
            curr=max(curr,recursion(prices,pos+1,!buy, t-1)+prices[pos]);
        }
        else
        {
             curr=max(curr,recursion(prices,pos+1,!buy, t)-prices[pos]);
        }
        return dp[buy][t][pos]=curr;
        
    }
    int maxProfit(vector<int>& prices) 
    {
        dp.resize(2, vector<vector<int>> (3, vector<int>(prices.size(),-1)));
        
        int res=recursion(prices,0,false,2);
        return res;
    }
};