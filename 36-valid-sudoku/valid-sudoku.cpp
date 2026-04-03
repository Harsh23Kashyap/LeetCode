class Solution {
public:
bool valid(vector<vector<char>>& board, int i, int j){

    cout << "Validating (" << i << "," << j << ") = " << board[i][j] << "\n";

    for(int k=0;k<board.size();k++){
        if(k!=i and board[k][j]==board[i][j]){
            cout << "Column conflict at (" << k << "," << j << ")\n";
            return false;
        }
    }

    for(int k=0;k<board[0].size();k++){
        if(k!=j and board[i][k]==board[i][j]){
            cout << "Row conflict at (" << i << "," << k << ")\n";
            return false;
        }
    }

    int sty=(i/3)*3;
    int eny=sty+3;
    int stx=(j/3)*3;
    int enx=stx+3;

    for(int k=sty;k<eny;k++){
        for(int l=stx;l<enx;l++){
            if(k==i and l==j) continue;
            if(board[k][l]==board[i][j]){
                cout << "Box conflict at (" << k << "," << l << ")\n";
                return false;
            }
        }
    }

    cout << "Valid placement at (" << i << "," << j << ")\n";
    return true;
}

    bool pass(int i, int j, vector<vector<char>>& board){

        cout << "\nCALL pass(" << i << "," << j << ")\n";

        if(i==board.size()){
            cout << "Reached end → returning true\n";
            return true;
        }

        if(j==board[0].size()){
            cout << "Move to next row\n";
            return pass(i+1,0,board);
        }

        cout << "Current cell (" << i << "," << j << ") = " << board[i][j] << "\n";

        if(board[i][j]=='.'){
            cout << "Cell is empty, skipping (no fill logic here)\n";
            return pass(i,j+1,board);
        }
        
        // unreachable but keeping prints for debugging flow
        cout << "Checking validity at (" << i << "," << j << ")\n";

        if(valid(board,i,j)){
            cout << "Valid → moving forward\n";
            if(pass(i,j+1,board))
                return true;
        }

        cout << "Returning false at (" << i << "," << j << ")\n";
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        cout << "Starting validation...\n";
        bool ans = pass(0,0,board);
        cout << "Final result = " << ans << "\n";
        return ans;
    }
};