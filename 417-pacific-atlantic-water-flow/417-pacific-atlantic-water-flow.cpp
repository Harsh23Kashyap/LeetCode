class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,int prev)
    {   
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]<prev)
            return;
        vis[i][j]=1;
        dfs(i+1,j,vis,grid,grid[i][j]);
        dfs(i-1,j,vis,grid,grid[i][j]);
        dfs(i,j+1,vis,grid,grid[i][j]);
        dfs(i,j-1,vis,grid,grid[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> res;
        for(int i=0;i<m;i++)
        {
            dfs(0,i,pacific,heights,heights[0][i]);
            dfs(n-1,i,atlantic,heights,heights[n-1][i]);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,0,pacific,heights,heights[i][0]);
            dfs(i,m-1,atlantic,heights,heights[i][m-1]);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(atlantic[i][j]==1 && pacific[i][j]==1) 
                    res.push_back({i,j});
            
        return res;
    }
};