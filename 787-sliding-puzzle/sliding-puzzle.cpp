class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>> u;
        u[0]={1,3};
        u[1]={0,2,4};
        u[2]={1,5};
        u[3]={0,4};
        u[4]={3,5,1};
        u[5]={4,2};
        queue<pair<string,int>> q;
        int zero=-1;
        unordered_set<string> us;
        string s="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                s+=to_string(board[i][j]);
                if(board[i][j]==0)
                    zero=i*3+j;
            }
        }
        
        q.push({s,zero});
        us.insert(s);
        int c=0;
        while(!q.empty())
        {
            
            int sz=q.size();
            while(sz--){
                auto [curr, cz]=q.front();
                // cout<<"Current "<<curr<<endl;
                q.pop();
                if(curr=="123450")
                    return c;
                
                vector<int> dx=u[cz];
                
                for(auto jt:dx){
                    string nz=curr;
                    nz[cz]=nz[jt];
                    nz[jt]='0';
                    // cout<<nz<<endl;
                    if(us.find(nz)==us.end())
                    {
                        us.insert(nz);
                        q.push({nz,jt});
                    }
                }
            }
            
            c++;
        }
        
        // cout<<s<<endl;
        return -1;
    }
};