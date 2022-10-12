class Solution {
public:
    int minInsertions(string s) 
    {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        dp[0][0]=0;
//         for(int i=0;i<=n;i++)
//         {
//             dp[0][i]=i;
//             dp[i][0]=i;
//         }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==rev[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
//          for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=n;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//              cout<<endl;
//         }
        return n-dp[n][n];
    }
};