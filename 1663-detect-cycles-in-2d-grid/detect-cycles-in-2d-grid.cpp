class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
vector<vector<int>> vis;
bool cycle(vector<vector<char>>& grid, int i , int j, int par){

    vis[i][j]=1;
    int px=par/grid[0].size(),py=par%grid[0].size();

    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dx[k+1];
        if(nx<0 or ny<0 or nx>=grid.size() or ny>=grid[0].size())
            continue;
        if(grid[i][j]!=grid[nx][ny])
            continue;
        if(vis[nx][ny]==-1){

            if(cycle(grid,nx,ny,i*grid[0].size()+j)){
                return true;
            }
        }
        else{
            if(px==nx and py==ny)
                continue;
            else
            return true;
        }
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> a(m, vector<int> (n,-1));
        vis=a;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==-1){
                    if(cycle(grid,i,j, -1))
                        return true;
                }
            }
        }
        return false;

    }
};