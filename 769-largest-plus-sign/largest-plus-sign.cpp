class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        unordered_set<int> st;
        for (auto &m : mines) {
            st.insert(m[0] * n + m[1]);
        }

        vector<vector<int>> dp(n, vector<int>(n, n));

        // LEFT
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (st.count(i*n + j)) count = 0;
                else count++;
                dp[i][j] = min(dp[i][j], count);
            }

            // RIGHT
            count = 0;
            for (int j = n-1; j >= 0; j--) {
                if (st.count(i*n + j)) count = 0;
                else count++;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        // UP & DOWN
        for (int j = 0; j < n; j++) {
            int count = 0;

            // UP
            for (int i = 0; i < n; i++) {
                if (st.count(i*n + j)) count = 0;
                else count++;
                dp[i][j] = min(dp[i][j], count);
            }

            // DOWN
            count = 0;
            for (int i = n-1; i >= 0; i--) {
                if (st.count(i*n + j)) count = 0;
                else count++;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};