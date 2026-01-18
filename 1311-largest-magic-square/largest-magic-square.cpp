class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> prow(m, vector<int>(n + 1, 0));
        vector<vector<int>> pcol(m + 1, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prow[i][j + 1] = prow[i][j] + grid[i][j];
                pcol[i + 1][j] = pcol[i][j] + grid[i][j];
            }
        }

        int ans = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = prow[i][j + k] - prow[i][j];
                    bool ok = true;
 
                    for (int r = i; r < i + k && ok; r++) {
                        if (prow[r][j + k] - prow[r][j] != target)
                            ok = false;
                    }
 
                    for (int c = j; c < j + k && ok; c++) {
                        if (pcol[i + k][c] - pcol[i][c] != target)
                            ok = false;
                    }
 
                    int d1 = 0, d2 = 0;
                    for (int a = 0; a < k; a++) {
                        d1 += grid[i + a][j + a];
                        d2 += grid[i + a][j + k - 1 - a];
                    }

                    if (d1 != target || d2 != target)
                        ok = false;

                    if (ok)
                        ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};
