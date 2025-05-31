class Solution {
public:
    long long nextMove(int dest, vector<int> & board, vector<int>& dp){
        if(dest==board.size()-1)
            return 0;
        if(dest>=board.size())
        return 1e5;


        if(dp[dest]!=1e5)
        return dp[dest];

        int mini=INT_MAX;
        // if(board[dest]!=-1)
        //     dest=board[dest];


        for(int k=1;k<=6;k++){
            long long next=dest+k;
            cout<<"Moving to "<<next<<endl;
            if(next>=board.size())
                break;
            if (board[next] != -1) {
                next = board[next];
            }
            int curr=nextMove(next,board,dp);
            if(curr<=1e4)
            {
                mini=min(mini,curr);
            }
        }
        cout<<" At "<<dest<<" "<<mini<<endl;
        if(mini<=10000)
        return dp[dest]=1+mini;

        return dp[dest]=1e5;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> newboard;
        newboard.push_back(-1);
        bool ltr=true;
        for(int i=board.size()-1;i>=0;i--)
        {
            if(ltr){
                for(int j=0;j<board.size();j++){
                     newboard.push_back(board[i][j]);
                }
            }
           else{
                for(int j=board.size()-1;j>=0;j--){
                     newboard.push_back(board[i][j]);
                }
            }
            ltr=!ltr;
        }
    vector<bool> visited(newboard.size(), false);
    visited[1]=true;
    
   queue<int> q;
   int c=0;
    q.push(1);
    while(!q.empty()){
        int sz=q.size();
        c++;
        while(sz--){

            auto dest=q.front();
            q.pop();
            for (int k = 1; k <= 6; k++) {
            int next = dest + k;
            if (next >= newboard.size()) continue;

            if (next == newboard.size() - 1) return c; 

            if (newboard[next] != -1) {
                next = newboard[next];
            }

            if (next == newboard.size() - 1) return c; 

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }



           
          
        
        }
    }
    return -1;
    }
};