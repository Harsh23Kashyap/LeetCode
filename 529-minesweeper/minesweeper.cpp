class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(),n=board[0].size();
        int x=click[0],y=click[1];
        if(board[x][y]=='M'){
            board[x][y]='X';
            return board;
        }
        vector<int> dx = {-1, -1, -1,  0, 0, 1, 1, 1};
        vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            char val=board[it.first][it.second];
            if(val=='M')
                continue;
            
            if(val=='E'){
                int c=0;
                for(int k=0;k<8;k++)
                {
                    int nx=dx[k]+it.first;
                    int ny=dy[k]+it.second;
                    if(nx<0 or ny<0 or nx>=board.size() or ny>=board[0].size())
                        continue;

                    if(board[nx][ny]=='M')
                        c++;
                
                }
                if(c>0){
                    board[it.first][it.second]=c+'0';
                }
                else{
                     board[it.first][it.second]='B';
                    for(int k=0;k<8;k++)
                    {
                        int nx=dx[k]+it.first;
                        int ny=dy[k]+it.second;
                        if(nx<0 or ny<0 or nx>=board.size() or ny>=board[0].size())
                            continue;

                        if(board[nx][ny]=='E')
                                q.push({nx,ny});
                    
                    }
                }
            }

        }
        return board;



    }
};