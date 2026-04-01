class Solution {
public:
    unordered_map<int, vector<int>> u = {
        {0,{1,3}}, {1,{0,2,4}}, {2,{1,5}},
        {3,{0,4}}, {4,{1,3,5}}, {5,{2,4}}
    };

unordered_set<string> ss;
    bool check(string res){
        return res=="123450"; 
    }


    int solve(int k, int l, vector<vector<int>>& board){
        string s="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                s+=to_string(board[i][j]);
            }
        }
        queue<pair<string,int>> q;
        int z=k*3+l;
        q.push({s,z});
        int c=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                // cout<<it.first<<endl;
                q.pop();
                if(check(it.first))
                return c;

                int ind0=it.second;
               
                for(auto aaaaa:u[ind0]){
                    string backup=it.first;
                    swap(backup[ind0],backup[aaaaa]);
                    if(ss.find(backup)==ss.end())
                    {
                        ss.insert(backup);
                        q.push({backup,aaaaa});
                    }
                }




                
            }
            c++;
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0)
                    return solve(i,j,board);
            }
        }
        return -1;

    }
};