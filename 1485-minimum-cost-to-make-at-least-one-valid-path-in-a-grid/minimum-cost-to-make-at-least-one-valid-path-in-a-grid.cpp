class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [cost, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            // important optimization
            if(cost > dist[x][y]) continue;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int newCost = cost + ((k == grid[x][y] - 1) ? 0 : 1);

                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }

        return dist[m-1][n-1];
    }
};