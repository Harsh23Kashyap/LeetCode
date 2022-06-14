class Solution {
public:
    int longestCommonSubsequence(string a, string b) 
    {
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
//         cout<<"  ";
//         for(int j=0;j<m;j++)
//             cout<<b[j]<<"  ";
//         cout<<" \\"<<endl;
        
//         string x=a+"\\";
//         for(int i=0;i<n+1;i++)
//         {
//             cout<<x[i]<<"  ";
//             for(int j=0;j<m+1;j++)
//             {
//                cout<<dp[i][j]<<"  ";
//             }
//             cout<<endl;
//         }
        return dp[0][0];
        
        
    }
};