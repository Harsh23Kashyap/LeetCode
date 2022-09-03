class Solution {
public:
    string shortestCommonSupersequence(string a, string b) 
    {
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        
        int i=a.size();
        int j=b.size();
        while(i>0 and j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans=b[j-1]+ans;
                i--;
                j--;
            }
            
            else if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
              

        }
        
        int i1=0,i2=0;
        string res;
        for(char ch:ans)
        {
            while(a[i1]!=ch)
                res.push_back(a[i1++]);
            while(b[i2]!=ch)
                res.push_back(b[i2++]);
            res+=ch;
            i1++;
            i2++;
            
        }
        res+=a.substr(i1)+b.substr(i2);
        return res;
    }
};