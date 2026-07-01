class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool canReach(vector<vector<int>>& dist, int safe) {
        int n = dist.size();

        if (dist[0][0] < safe)
            return false;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            if (x == n - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !vis[nx][ny] &&
                    dist[nx][ny] >= safe) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int low = 0;
        int high = 2 * n;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (canReach(dist, mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};