class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int row,col;
        for(int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='R')
                {
                    row=i;
                    col=j;
                    goto pass;
                }
            }
        }
        pass:
        int count=0;
        //up
        int i;
        for(i=row-1;i>=0;i--)
        {
            if(board[i][col]=='p')
            {
                count++;
                break;
            }
            else if(board[i][col]=='B')
                break;
        }
        //down
        for(i=row+1;i<8;i++)
        {
            if(board[i][col]=='p')
            {
                count++;
                break;
            }
            else if(board[i][col]=='B')
                break;
        }
        //left
        for(i=col-1;i>=0;i--)
        {
            if(board[row][i]=='p')
            {
                count++;
                break;
            }
            else if(board[row][i]=='B')
                break;
        }
        for(i=col+1;i<8;i++)
        {
            if(board[row][i]=='p')
            {
                count++;
                break;
            }
            else if(board[row][i]=='B')
                break;
        }
        return count;
    }
};