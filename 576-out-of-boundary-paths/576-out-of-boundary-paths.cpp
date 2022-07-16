class Solution {
public:
    int mod = 1000000007;
    int dp[51][51][51];
    int bfs(int m, int n, int maxMove, int i, int j)
    {
        
        if(i<0 or j<0 or i>=m or j>=n)
        {
            return 1;
        }
        if(maxMove<=0)
            return 0;
        //cout<<i<<" , "<<j<<" "<<maxMove<<endl;
        if(dp[i][j][maxMove]!=-1)
          return dp[i][j][maxMove]; 
        long long res=bfs(m,n,maxMove-1,i-1,j);
        res+=bfs(m,n,maxMove-1,i,j-1);
        res+=bfs(m,n,maxMove-1,i+1,j);
        res+=bfs(m,n,maxMove-1,i,j+1);
        return dp[i][j][maxMove]=res%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(dp,-1,sizeof(dp));
        return bfs(m,n,maxMove,startRow,startColumn)%mod;
        
        
    }
};