class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix[0].size();i++)
            
            dp[0][i]=matrix[0][i];
        
       
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                //cout<<i<<" "<<j<<endl;
                int op1=(j>0)?dp[i-1][j-1]:INT_MAX;
                int op2=dp[i-1][j];
                int op3=(j<matrix[0].size()-1)?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min(op1,min(op2,op3));
            }
        }
        
        return *min_element(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
    }
};