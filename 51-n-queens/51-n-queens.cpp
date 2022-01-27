class Solution {
public:
    vector<vector<string>> ans;
    bool isPossible(vector<string>&v, int r, int c)
    {
       int i, j;
        for (i = 0; i < r; i++)
            if (v[i][c]=='Q')
                return false;

        for (i = r-1, j = c-1; i >= 0 and j >= 0; i--, j--)
            if (v[i][j]=='Q')
                return false;

        for (i = r-1, j = c+1; i >= 0 and j < v.size(); i--, j++)
            if (v[i][j]=='Q')
                return false;

        return true;
    }
    void NQueen(vector<string>&v, int i)
    {
        if(i==v.size())
        {
            ans.push_back(v);
            return;
        }
        for(int j=0;j<v[i].size();j++)
        {
            if(isPossible(v,i,j))
            {
                v[i][j]='Q';
                NQueen(v,i+1);
                v[i][j]='.';
            }
        }
    } 
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> v;
        if(n==2 || n==3) return ans;
        //if(n==1) 
            
        for(int i=0;i<n;i++)
        {
            string s;
            s.append(n,'.');
            v.push_back(s);
        }
        NQueen(v,0);
        return ans;
    }
};