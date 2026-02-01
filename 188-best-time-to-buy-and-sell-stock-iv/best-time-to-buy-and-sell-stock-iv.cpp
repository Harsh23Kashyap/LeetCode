class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp[i][ck][bought]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int ck = k - 1; ck >= 0; ck--) 
            {

                // bought = 1
                dp[i][ck][1] = max(
                    prices[i] + dp[i + 1][ck + 1][0], // sell
                    dp[i + 1][ck][1]                  // hold
                );

                // bought = 0
                dp[i][ck][0] = max(
                    -prices[i] + dp[i + 1][ck][1],    // buy
                    dp[i + 1][ck][0]                  // skip
                );
            }
        }

        return dp[0][0][0];
    }
};
