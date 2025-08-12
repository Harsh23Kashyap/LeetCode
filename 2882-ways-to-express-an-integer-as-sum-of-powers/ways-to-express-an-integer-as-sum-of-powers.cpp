class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int fastpow(int base, int exp) {
        long long res = 1, b = base;
        while (exp > 0) {
            if (exp & 1) res = (res * b) % MOD;
            b = (b * b) % MOD;
            exp >>= 1;
        }
        return (int)res;
    }

    int dfs(int n, int i, const vector<int>& pp, vector<vector<int>>& dp) {
        if (n == 0) return 1;           
        if (n < 0 || i == (int)pp.size()) 
            return 0;  
        if (dp[n][i] != -1) 
        return dp[n][i];
 
        int take = dfs(n - pp[i], i + 1, pp, dp);

        // skip current power
        int skip = dfs(n, i + 1, pp, dp);

        return dp[n][i] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        int maxNum = 1;
        while (pow(maxNum + 1, x) <= n) maxNum++;

        vector<int> pp;
        for (int i = 1; i <= maxNum; ++i) {
            pp.push_back((int)pow(i, x));
        }

        vector<vector<int>> dp(n + 1, vector<int>(maxNum + 1, -1));
        return dfs(n, 0, pp, dp);
    }
};
