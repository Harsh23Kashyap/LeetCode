class Solution {
public:
    void recur(int n, int open,int close,char *out,int i,vector<string>& res)
    {
        if(i==2*n)
        {
            out[i]='\0';
            res.push_back(out);
            return;
        }
        if(open<n)
        {
            out[i]='(';
            recur(n,open+1,close,out,i+1,res);
        }
        if(close<open)
        {
            out[i]=')';
            recur(n,open,close+1,out,i+1,res);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        char out[18]="";
        recur(n,0,0,out,0,res);
        return res;
        
    }
};