class Solution {
public:
bool valid(int i ,int j, int m, int n){
    return i>=0 and j>=0 and i<m and j<n;
}
vector<int> dx={-1,0,1,0,-1};
void check(vector<vector<char>> & grid, int i, int j, vector<vector<int>>& vis){
    if(!valid(i,j,grid.size(),grid[0].size()) or vis[i][j]!=-1)
        return  ;
    if(grid[i][j]!='1')
        return;
    vis[i][j]=1;

    for(int k=0;k<4;k++){
        int nx=dx[k]+i;
        int ny=dx[k+1]+j;
        check(grid,nx,ny,vis);
    }


}
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),-1));
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==-1 and grid[i][j]=='1'){
                    check(grid,i,j,vis);
                    c++;
                }
            }
        }
        return c;
    }
};