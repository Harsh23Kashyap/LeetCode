class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
         
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, 0)));
        
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) { 
                    dp[i][j][0] = (i == 0 ? 1 : dp[i-1][j][0] + 1);   
                    dp[i][j][1] = (j == 0 ? 1 : dp[i][j-1][1] + 1);   
                    dp[i][j][2] = 1;
                    if (i > 0 && j > 0) {
                        dp[i][j][2] = min({dp[i-1][j-1][2], dp[i-1][j][0], dp[i][j-1][1]}) + 1;
                    }

                     int minWidth = dp[i][j][1];
                    for (int k = i; k >= 0 && mat[k][j] == 1; k--) {
                        minWidth = min(minWidth, dp[k][j][1]);
                        sum += minWidth;
                    }
                }
            }
        }
        
        return sum;
    }
};
