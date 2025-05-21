class Solution {
public:
    vector<vector<int>> dx={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        queue<pair<int,int>> q;
        unordered_set<int> u;
        q.push({click[0],click[1]});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                int tc=0;
                for(auto td:dx){
                    int nx=td[0]+it.first,ny=td[1]+it.second;
                    if(nx>=0 and ny>=0 and nx<board.size() and ny<board[0].size() and u.find(nx*board[0].size()+ny)==u.end()){
                        if(board[nx][ny]>='0' and board[nx][ny]<='9')
                        continue;
                        if(board[nx][ny]=='M'){
                            tc++;
                        }
                    }
                }
                if(tc>0){
                    board[it.first][it.second]=char('0'+tc);
                }
                else{
                     board[it.first][it.second]='B';
                    for(auto td:dx){
                        int nx=td[0]+it.first,ny=td[1]+it.second;
                        if(nx>=0 and ny>=0 and nx<board.size() and ny<board[0].size() and u.find(nx*board[0].size()+ny)==u.end()){
                            u.insert(nx*board[0].size()+ny);
                            board[nx][ny]='B';
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return board;
    }
};