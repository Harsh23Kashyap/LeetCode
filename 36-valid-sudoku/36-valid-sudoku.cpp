class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        return solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size() ; j++)
            {
                if(board[i][j] != '.')
                {
                    cout<<" i - "<<i<< " and j - "<<endl;
                    cout<<board[i][j]<<" ";
                   if(!is_valid(board, i, j, board[i][j]))
                   {
                       cout<<"False"<<endl;;
                        return false;
                   }
                    cout<<"True"<<endl;
                }
            }
        }
        return true;
    }
    
    bool is_valid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            if(!(i==row) and board[i][col] == c)
                return false;
            if(!(col==i) and board[row][i] == c )
                return false;
            if(!(row==(3*(row/3)+i/3) and col==3*(col/3)+i%3) and board[3*(row/3)+i/3][3*(col/3)+i%3] == c) 
                return false;
        }
        return true;
    }
};