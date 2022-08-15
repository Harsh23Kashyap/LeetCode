class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        
        for(int i=0;i<matrix[0].size();i++)
            dp[0][i]=matrix[0][i];
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int ans=INT_MAX;
                for(int k=0;k<matrix[0].size();k++)
                {
                    if(j!=k)
                        ans=min(ans,dp[i-1][k]);
                }
                dp[i][j]=matrix[i][j]+ans;
            }
        }
      
        
        
        return *min_element(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
        
    }
};