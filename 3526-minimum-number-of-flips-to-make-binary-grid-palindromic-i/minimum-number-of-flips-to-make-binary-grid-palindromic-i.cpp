class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                int left = grid[i][j];
                int right = grid[i][n - 1 - j];
                if (left != right) {
                    rowFlips++;
                }
            }
        }

        int colFlips = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m / 2; i++) {
                int top = grid[i][j];
                int bottom = grid[m - 1 - i][j];
                if (top != bottom) {
                    colFlips++;
                }
            }
        }

        return min(rowFlips, colFlips);
    }
};