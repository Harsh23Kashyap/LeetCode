class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        deque<pair<int,int>> dq;

        dq.push_front({0,0});
        dist[0][0] = 0;

        vector<vector<int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!dq.empty()) {

            auto [x,y] = dq.front();
            dq.pop_front();

            for(int k=0;k<4;k++) {

                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;

                int cost = (grid[x][y] == k+1) ? 0 : 1;

                if(dist[x][y] + cost < dist[nx][ny]) {

                    dist[nx][ny] = dist[x][y] + cost;

                    if(cost == 0)
                        dq.push_front({nx,ny});
                    else
                        dq.push_back({nx,ny});
                }
            }
        }

        return dist[m-1][n-1];
    }
};