class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, int i, int j, vector<pair<int, int>>& region) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (board[i][j] != 'O')
            return true;

        board[i][j] = '#';
        region.push_back({i, j});

        bool up    = dfs(board, i - 1, j, region);
        bool down  = dfs(board, i + 1, j, region);
        bool left  = dfs(board, i, j - 1, region);
        bool right = dfs(board, i, j + 1, region);

        return up && down && left && right;
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    vector<pair<int, int>> region;
                    bool isSurrounded = dfs(board, i, j, region);
                    
                    for (auto [x, y] : region) {
                        board[x][y] = isSurrounded ? 'X' : 'O';
                    }
                }
            }
        }
    }
};
