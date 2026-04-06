class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
bool pass(int i, int j, vector<vector<char>>& board, string w, int l, unordered_set<int>& vis){
    if(l==w.size())
    return true;

    for(int k=0;k<4;k++){
        int nx=i+dx[k],ny=j+dx[k+1];
        if(vis.find(nx*board[0].size()+ny)!=vis.end() )
            continue;
        if(nx<0 or ny<0 or nx>=board.size() or ny>=board[0].size())
        continue;

        if(board[nx][ny]!=w[l])
        continue;

        vis.insert(nx*board[0].size()+ny);
        if(pass(nx,ny,board,w,l+1,vis))
        return true;

        vis.erase(nx*board[0].size()+ny);
    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    unordered_set<int> vis;
                    vis.insert(i*board[0].size()+j);
                    if(pass(i,j,board,word,1,vis ))
                        return true;
                }
            }
        }
        return false;
        
        
    }
};