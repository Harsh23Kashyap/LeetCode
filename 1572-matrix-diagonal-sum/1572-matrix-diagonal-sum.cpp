class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int even=0;
        int n=mat.size();
        if(mat.size()%2!=0)
            even=mat[n/2][n/2];
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=mat[i][i];
        for(int i=0,j=n-1;j>=0 and i<n;i++,j--)
            sum+=mat[i][j];
        
        return sum-even;
        
    }
};