class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
         
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }
 
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> up(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) left[i][j] = 0;
                else left[i][j] = (j == 0 ? 1 : left[i][j-1] + 1);
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--) {
                if (grid[i][j] == 0) right[i][j] = 0;
                else right[i][j] = (j == n-1 ? 1 : right[i][j+1] + 1);
            }
        }
 
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 0) up[i][j] = 0;
                else up[i][j] = (i == 0 ? 1 : up[i-1][j] + 1);
            }
        }
 
        for (int j = 0; j < n; j++) {
            for (int i = n-1; i >= 0; i--) {
                if (grid[i][j] == 0) down[i][j] = 0;
                else down[i][j] = (i == n-1 ? 1 : down[i+1][j] + 1);
            }
        }
 
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int order = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                    ans = max(ans, order);
                }
            }
        }

        return ans;
    }
};