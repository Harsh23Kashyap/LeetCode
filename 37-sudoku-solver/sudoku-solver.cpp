// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
        
//     }
// };
class Solution {
public:
bool valid(vector<vector<char>>& board, int i, int j){
    for(int k=0;k<board.size();k++){
        if(k!=i and board[k][j]==board[i][j])
            return false;
    }
     for(int k=0;k<board[0].size();k++){
        if(k!=j and board[i][k]==board[i][j])
            return false;
    }

    int sty=(i/3)*3;
    int eny=sty+3;
    int stx=(j/3)*3;
    int enx=stx+3;
    for(int k=sty;k<eny;k++){
        for(int l=stx;l<enx;l++){
            if(k==i and l==j)
            continue;
            if(board[k][l]==board[i][j])
            return false;
        }
    }
    return true;

    
}
    bool pass(int i, int j, vector<vector<char>>& board){
        if(i==board.size())
        return true;

        if(j==board[0].size())
            return pass(i+1,0,board);

        if(board[i][j]!='.')
            return pass(i,j+1,board);
        
        //tofill

        for(char ch='1';ch<='9';ch++){
            board[i][j]=ch;
            if(valid(board,i,j)){
                if(pass(i,j+1,board))
                    return true;
            }
             board[i][j]='.';
        }
        return false;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        
        return pass(0,0,board);
        
    }
};