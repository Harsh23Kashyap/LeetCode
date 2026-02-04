class Solution {
public:
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& d, vector<vector<int>>& dp) {
        if (i >= m || j >= n)
            return INT_MAX;  

        if (i == m - 1 and j == n - 1)
            return max(1, 1 - d[i][j]);  

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = dfs(i + 1, j, d,dp);
        int right = dfs(i, j + 1, d,dp);

        int need = min(down, right) - d[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& d) {
        m = d.size();
        n = d[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, d,dp);
    }
};
