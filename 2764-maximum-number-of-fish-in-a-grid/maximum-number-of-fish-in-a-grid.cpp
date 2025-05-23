class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
    int dfs(vector<vector<int>> grid, int i, int j, int m, int n, vector<vector<int>>& vis){
       

        int x= grid[i][j];
        
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dx[k+1];
            if(nx<0 or ny<0 or nx>=m or ny>=n or vis[nx][ny]!=-1 or grid[nx][ny]==0)
                continue; 
            else{
                vis[nx][ny]=1;
                x+=dfs(grid,nx,ny,m,n,vis);
            }
        }
        return x;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,-1));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    if(vis[i][j]==-1){
                        vis[i][j]=1;
                        int curr=dfs(grid,i,j,n,m, vis);
                        maxi=max(maxi,curr);
                    }
                }
            }
        }
        return maxi;
    }
};