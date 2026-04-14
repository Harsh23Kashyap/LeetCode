class Solution {
public:
int m=1e9+7;
int pass(int i, int rt,vector<vector<int>>& types,vector<vector<int>> &dp){
    if(rt<0){
        return -1;
    }
    if(rt==0){
        return 1;
    }
    if(i>=types.size())
        return -1;
    if(dp[rt][i]!=-1)
        return dp[rt][i];
    int res=0;
    for(int k=0;k<=types[i][0];k++){
        int usethem=k*types[i][1];
        if(rt<usethem)
            continue;
        int curr=pass(i+1,rt-usethem, types,dp);
        if(curr==-1)
            continue;
        res=(res+curr)%m;
    }   
    return dp[rt][i]=res%m;
}
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(target+1, vector<int> (types.size()+1,-1));
        return pass(0,target,types,dp);
    }
};