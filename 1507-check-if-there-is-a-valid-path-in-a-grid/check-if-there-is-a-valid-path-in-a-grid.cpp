class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),0));
        vis[0][0]=1;
        vector<vector<pair<int,int>>> dx={
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{1,0},{0,1}},
            {{0,-1},{-1,0}},
            {{-1,0},{0,1}},
        };

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==grid.size()-1 and y==grid[0].size()-1)
                return true;
            int val=grid[x][y]; 
            cout<<x<<" "<<y<<endl;
            for(auto dir:dx[val-1]){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx<0 or ny<0 or nx>=grid.size() or ny>=grid[0].size())
                    continue;

                if(vis[nx][ny])
                    continue;
                
                // vis[nx][ny]=1;
                int nval=grid[nx][ny];
                for(auto k:dx[nval-1]){
                    int nnx=nx+k.first;
                    int nny=ny+k.second;
                    if(nnx==x and nny==y){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                        break;
                    }
                }
                
            }
        }
        return false;
    }
};