class Solution {
public:
    int countSquares(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=grid[0][0];
        int sum=grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0]=grid[i][0];
            sum+=dp[i][0];
        }
        
        for(int i=1;i<n;i++)
        {
            dp[0][i]=grid[0][i];
            sum+=dp[0][i];
        }
        
        //cout<<sum<<endl;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=1+(min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])));
                    sum+=dp[i][j];
                    //cout<<i<<" , "<<j<<" - "<<sum<<endl;
                }
            }
        }
        return sum;
                
        
    }
};