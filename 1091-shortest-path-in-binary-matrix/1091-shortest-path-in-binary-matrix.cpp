class Solution {
    bool isOutOfBounds(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size()) return true;
        if(c < 0 || c >= grid[r].size()) return true;    
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {
            {-1,-1},    {-1,0},     {-1,1},
            {0,-1},                 {0,1},
            {1,-1},     {1,0},      {1,1}
        };
        using pii = pair<int,int>;
        int ROWS = grid.size();
        if(ROWS == 0) return 0;
        int COLS = grid[0].size();
        queue<pii> q;
        if(grid[0][0] == 0) 
            q.push({0,0});
        int steps = 0;
        while(!q.empty()) {
            int qSize = q.size();
            steps++;
            for(int i = 0; i < qSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                if(r == ROWS - 1 && c == COLS - 1) return steps;
                for(auto& dir : dirs) {
                    int dr = dir[0] + r;
                    int dc = dir[1] + c;
                    if(isOutOfBounds(grid, dr, dc)) continue;
                    if(grid[dr][dc] == 1) continue;
                    grid[dr][dc] = 1;
                    q.push({dr,dc});
                }
            }
        }
        return -1;
    }
};