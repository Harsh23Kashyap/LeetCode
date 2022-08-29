class Solution {
public:
    void DFS(vector<vector<char>>& grid,int i, int j ) 
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1' )
        {
            cout<<"make "<<i<<" "<<j<<" zero"<<endl;
            grid[i][j]='0';
            DFS(grid,i-1,j);
            DFS(grid,i+1,j);
            DFS(grid,i,j+1);
            DFS(grid,i,j-1);
        }
        //grid[i][j]=-1;
        //return 0;
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int total=0;
        for (int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                {
                    cout<<i<<" "<<j<<endl;
                    total++;
                    DFS(grid,i,j);
                }
        return total;
    }
};