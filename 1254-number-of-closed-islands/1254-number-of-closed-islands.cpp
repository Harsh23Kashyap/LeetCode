class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};
    bool dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int i, int j)
    {
        // cout<<"In - "<<i<<" , "<<j<<endl;
        if(i==0 or j==0 or i==grid.size()-1 or j==grid[0].size()-1)
        {
            if(grid[i][j]==0)
            {
                return false;
            }
            else
                return true;
        }
        if(vis[i][j]==-1)
            return true;
        
        if(grid[i][j]==1)
            return true;
        if(vis[i][j]!=0)
            return vis[i][j]==2;
        
        
       bool res=true;
        vis[i][j]=-1;
        for(int k=0;k<4;k++)
        {
            res=res&dfs(grid,vis,i+dx[k],j+dy[k]);
        }
        if(res)
            vis[i][j]=2;
        else
            vis[i][j]=1;
        // cout<<"OUT"<<endl;
        return vis[i][j]==2;
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=1;i<grid.size()-1;i++)
        {
            for(int j=1;j<grid[0].size()-1;j++)
            {
                //cout<<"New "<<i<<" , "<<j<<endl;
                if(vis[i][j]==0 and grid[i][j]==0 and dfs(grid,vis,i,j))
                    ans++;
            }
        }
        return ans;
    }
};