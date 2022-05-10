class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            grid.push_back(temp);
        }
        
        for(int i=0;i<guards.size();i++)
            grid[guards[i][0]][guards[i][1]]=1;
        
        for(int i=0;i<walls.size();i++)
            grid[walls[i][0]][walls[i][1]]=1;
        
        
        for(int i=0;i<guards.size();i++)
        {
            int row=guards[i][0];
            int col=guards[i][1];
            for(int j=row-1;j>=0;j--)
            {
                if(grid[j][col]==1)
                    break;
                else
                    grid[j][col]=2;
            }
            
            for(int j=row+1;j<m;j++)
            {
                if(grid[j][col]==1)
                    break;
                else
                    grid[j][col]=2;
            }
            
            for(int j=col-1;j>=0;j--)
            {
                if(grid[row][j]==1)
                    break;
                else
                    grid[row][j]=2;
            }
            
            for(int j=col+1;j<n;j++)
            {
                if(grid[row][j]==1)
                    break;
                else
                    grid[row][j]=2;
            }
            
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
       for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    cnt++;
            }
        }
            
        
        return cnt;
        
    }
};