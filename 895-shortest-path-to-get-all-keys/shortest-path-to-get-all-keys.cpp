class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx, sy, maxKey = 0;
 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@') {
                    sx = i; sy = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    maxKey = max(maxKey, grid[i][j] - 'a' + 1);
                }
            }
        }

        queue<tuple<int,int,int>> q; // x, y, mask
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(64, false)));

        q.push({sx, sy, 0});
        vis[sx][sy][0] = true;

        int steps = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x, y, mask] = q.front();
                q.pop();

                if(mask == (1 << maxKey) - 1)
                    return steps;

                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    char ch = grid[nx][ny];
                    if(ch == '#') continue;

                    int newMask = mask;

                    // key
                    if(ch >= 'a' && ch <= 'f') {
                        newMask |= (1 << (ch - 'a'));
                    }

                    // lock
                    if(ch >= 'A' && ch <= 'F') {
                        if(!(mask & (1 << (ch - 'A'))))
                            continue;
                    }

                    if(vis[nx][ny][newMask]) continue;

                    vis[nx][ny][newMask] = true;
                    q.push({nx, ny, newMask});
                }
            }
            steps++;
        }

        return -1;
    }
};