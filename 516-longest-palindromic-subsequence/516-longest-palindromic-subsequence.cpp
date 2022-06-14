class Solution {
public:
    int longestPalindromeSubseq(string a) 
    {
        string b=a;
        reverse(a.begin(),a.end());
        int n=a.length();
        int m=b.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(a[i]==b[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
        
    }
};