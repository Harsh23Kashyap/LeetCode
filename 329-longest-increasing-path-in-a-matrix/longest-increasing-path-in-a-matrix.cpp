class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0, -1}; // Direction vectors (up, right, down, left)
    vector<vector<int>> dp;
    int maxi = 1;

    int dfs(int r, int c, int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];

        int longest = 0;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dx[k + 1];
            if (nx >= 0 && ny >= 0 && nx < r && ny < c && matrix[nx][ny] > matrix[i][j]) {
                longest = max(longest, dfs(r, c, nx, ny, matrix));
            }
        }

        dp[i][j] = 1 + longest; // 1 (for the current cell) + longest from neighbor
        maxi = max(maxi, dp[i][j]); // Update global max
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1)); // Initialize dp

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(m, n, i, j, matrix);
            }
        }

        return maxi;
    }
};
