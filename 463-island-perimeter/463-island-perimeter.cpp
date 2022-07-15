class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size())
            return true;
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    //cout<<"For "<<i<<" and "<<j<<endl;
                    if(check(grid,i-1,j) and grid[i-1][j]==0)
                        cnt++;
                     if(check(grid,i,j-1) and grid[i][j-1]==0)
                        cnt++;
                     if(check(grid,i+1,j) and grid[i+1][j]==0)
                        cnt++;
                     if(check(grid,i,j+1) and grid[i][j+1]==0)
                        cnt++;
                    if(i==0 )
                        cnt++;
                    if(i==grid.size()-1)
                        cnt++;
                    if(j==0 )
                        cnt++;
                    if(j==grid[0].size()-1)
                        cnt++;
                    //cout<<cnt<<endl;
                }
            }
        }
        return cnt;
        
    }
};