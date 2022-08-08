class Solution {
public:
    bool pass(string s, string p, vector<vector<int>> &dp, int i, int j)
    {
        //cout<<i<<"  and "<<j<<endl;
        // if(i<s.size() and j<p.size())
        // cout<<s[i]<<" -  "<<p[j]<<endl;
        if(i>=s.size() and j>=p.size())
            return true;
        if(i>=s.size())
        {
            for(int k=p.size()-1;k>=j;k-=2)
            {
                
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
        if(j>=p.size())
            return false;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans=false;
        // match .
        
        if(p[j]=='.' or s[i]==p[j])
        {
            //cout<<"Passing with . or same character for "<<i<<" - "<<j<<endl;
            ans|=pass(s,p,dp,i+1,j+1);
        }
        
        // skip *
        
        if(j+1<p.size() and p[j+1]=='*')
        {
            //cout<<"Passing with * and skipping for "<<i<<" - "<<j<<endl;
            ans|=pass(s,p,dp,i,j+2);
        }
        
        //add *
        
        if(j+1<p.size() and p[j+1]=='*' and (s[i]==p[j] or p[j]=='.'))
        {
            //cout<<"Passing with * and staying for "<<i<<" - "<<j<<endl;
            ans|=pass(s,p,dp,i+1,j);
        }
        
        
        
        return dp[i][j]=ans;
            
    }
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return pass(s,p,dp,0,0);
        
    }
};