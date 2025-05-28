#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Initialize the queue with all 0-cells and set their distance to 0
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Directions for up, down, left, right
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        // BFS from all zeros at once
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto& dir : directions){
                int nr = r + dir.first;
                int nc = c + dir.second;

                // Check boundaries and if we found a shorter path
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(dist[nr][nc] > dist[r][c] + 1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};
