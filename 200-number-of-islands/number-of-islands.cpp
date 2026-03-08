class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0')
            return ;
        cout<<i<<" "<<j<<endl;
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dx[k+1];
            dfs(x,y,grid);

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    c++;
                    dfs(i,j,grid);
                }
            }
        }
        return c;
    }
};