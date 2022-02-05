class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {   
        int result = 0;
        if(grid.size()*grid[0].size()<9) return 0;
        for(int i = 0; i < grid.size()-2; i++)
        {
            for(int j = 0; j < grid[i].size()-2 ; j++)
            {
                if(isMagicSquare(grid, i, j))
                {
                    result++;
                }
            }
        }
        return result;
    }
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j)
    {
        //if(i+2>=grid.size() || j+2>=grid.size()) return false;
        int col1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int col2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int col3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
        int row1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int row2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int row3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        int diag1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diag2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
        if(col1!=col2 || col2!=col3 || col3!=row1 || row2!=row3 || row3!=diag1 || diag1!=diag2)
            return false;
        cout<<"runs";
        set<int> s;
        for(int r=i;r<i+3;r++)
        {
            for(int c=j;c<j+3;c++)
            {
                if(grid[r][c]<=0 or grid[r][c]>9)
                    return false;
                s.insert(grid[r][c]);
            }
        }
        cout<<"runs";
        for(int i:s)
            cout<<i<<" ";
        if(s.size()!=9)
            return false;
        return true;
    }
};