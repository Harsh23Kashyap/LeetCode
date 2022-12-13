class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j, int emp)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]<0)
            return 0;
        //cout<<i<<" , "<<j<<" -"<<emp<<endl;
        if(grid[i][j]==2)
            return emp==0;
        
        grid[i][j]=-2;
        int tot= dfs(grid,i-1,j,emp-1)+dfs(grid,i+1,j,emp-1)+dfs(grid,i,j-1,emp-1)+dfs(grid,i,j+1,emp-1);
        grid[i][j]=0;
        return tot;
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int xs=0,ys=0,emp=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    xs=i,ys=j;
                }
                if(grid[i][j]==0)
                    emp++;
            }
        }
        
        return dfs(grid,xs,ys,emp+1);
        
    }
};