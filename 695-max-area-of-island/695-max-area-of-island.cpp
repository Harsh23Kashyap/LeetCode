class Solution 
{
public:
    int DFS(vector<vector<int>>& grid,int i, int j ) 
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 )
        {
            grid[i][j]=-1;
            return (1+DFS(grid,i-1,j)+DFS(grid,i+1,j)+DFS(grid,i,j+1)+DFS(grid,i,j-1));
        }
        //grid[i][j]=-1;
        return 0;
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        
        int res=0;
        for (int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                res=max(res, DFS(grid,i,j));
            }
        }
            
        return res;
    }
};