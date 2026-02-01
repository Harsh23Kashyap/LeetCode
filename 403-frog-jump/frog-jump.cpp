class Solution {
public:
int n;
int dfs(vector<int>& stones, int jump, int i, vector<vector<int>> &dp){
    if(i>=n)
    return false;
    if(i==n-1)
    return true;

    if(dp[i][jump]!=-1)
    return dp[i][jump];

    int currStones=stones[i];
    //k-1
    int jump1=jump-1+currStones;
    //k
    int jump2=jump+currStones;
    //k+1
    int jump3=jump+1+currStones;
    bool res=false;
    int it=0;
    if(jump-1>0){
        it=lower_bound(stones.begin(),stones.end(),jump1)-stones.begin();
        if(it<stones.size() and stones[it]==jump1)
            res= res or dfs(stones,jump-1,it,dp);
    }
    
    it=lower_bound(stones.begin(),stones.end(),jump2)-stones.begin();
    if(it<stones.size() and stones[it]==jump2)
        res= res or dfs(stones,jump,it,dp);

    it=lower_bound(stones.begin(),stones.end(),jump3)-stones.begin();
    if(it<stones.size() and stones[it]==jump3)
        res= res or dfs(stones,jump+1,it,dp);

    return  dp[i][jump]=res;

}
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
        return false;
        if(stones.size()==2)
        return true;

        n=stones.size();
        vector<vector<int>> dp(n, vector<int> (2005,-1));

        return dfs(stones,1,1,dp);
    }
};