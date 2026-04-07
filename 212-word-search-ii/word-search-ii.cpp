class Solution {
public:
class Trie{
    public:
    unordered_map<char,Trie*> children;
    char ch;
    bool ends;
    string str;
    Trie( char c){
        ch=c;
        ends=false;
        str="";
    }
};
Trie* root= new Trie('/');
void insert(string s){
    Trie* curr=root;

    for(int i=0;i<s.size();i++){
        if(!curr->children.count(s[i]))
            curr->children[s[i]]= new Trie(s[i]);
        curr= curr->children[s[i]];
    }
    curr->ends=true;
    curr->str=s;
}
vector<int> dx={-1,0,1,0,-1};
unordered_set<string> ans;
void search(Trie* root, vector<vector<char>>& board, int i, int j, vector<vector<bool>> &vis)
{
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
        return;

    if(vis[i][j])
        return;
    
    
    if(!root->children.count(board[i][j]))
        return;

    vis[i][j]=true;
    root=root->children[board[i][j]];

    if(root->ends)
        ans.insert(root->str);

   
    for(int k=0;k<4;k++){
        int nx=i+dx[k],ny=j+dx[k+1];
        search(root,board,nx,ny,vis);
        
    }
    vis[i][j]=false;

    
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto it:words)
            insert(it);
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(root->children.count(board[i][j]))
                {
                    vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
                    search(root,board,i,j, vis);
                }
            }
        }
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};