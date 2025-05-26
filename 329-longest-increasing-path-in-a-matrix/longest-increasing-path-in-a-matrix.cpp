class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
int maxi=1;
vector<vector<int>> dp;
int trya(int r, int c, int i, int j, vector<vector<int>>& m)
{

    if(dp[i][j]!=-1)
    return dp[i][j];
    int curr=0;
    for(int k=0;k<4;k++){
        int nx=i+dx[k],ny=j+dx[k+1];
        if(nx>=r or ny>=c or nx<0 or ny<0)
        continue;
        if(m[nx][ny]<=m[i][j])
        continue;
        curr=max(curr,trya(r,c,nx,ny,m));
    }
    dp[i][j]=max(dp[i][j],1+curr);

    maxi=max(maxi,dp[i][j]);
    return dp[i][j];

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dpp(m,vector<int> (n,-1));
        dp=dpp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                trya(m,n,i,j,matrix);
            }
        }
        return maxi;
    }
};