class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) 
                {
                    q.push({i,j});
                }
            }
        }
 
        if (q.empty() or q.size() == n * n)
            return -1;

        vector<int> dx = {-1,0,1,0,-1};

        int dist = 0;
        int curr=0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) 
            {
                auto [x,y] = q.front(); 
                q.pop();

                for (int k = 0; k < 4; k++) 
                {
                    int nx = x + dx[k], ny = y + dx[k+1];

                    if (nx >= 0 and ny >= 0 and nx < n and ny < n 
                        and grid[nx][ny] == 0) 
                        {
                        grid[nx][ny] = 1;  
                        curr=max(curr,dist+1);
                        q.push({nx, ny});
                    }
                }
            }

            dist++;
        }

        return curr;
    }
};