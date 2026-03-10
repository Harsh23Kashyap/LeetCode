class Solution {
public:
    int mod = 1e9+7;
    long long dp[201][201][3];

    long long dfs(int z, int o, int last, int limit){

        if(z==0 and o==0) 
            return 1;

        if(dp[z][o][last] != -1)
            return dp[z][o][last];

        long long ans = 0;

        if(last != 0)
        {
            for(int k=1; k<=limit and k<=z; k++){
                ans = (ans + dfs(z-k, o, 0, limit)) % mod;
            }
        }

        if(last != 1){
            for(int k=1; k<=limit && k<=o; k++){
                ans = (ans + dfs(z, o-k, 1, limit)) % mod;
            }
        }

        return dp[z][o][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp,-1,sizeof(dp));

        return dfs(zero, one, 2, limit); // 2 = start (no last)
    }
};