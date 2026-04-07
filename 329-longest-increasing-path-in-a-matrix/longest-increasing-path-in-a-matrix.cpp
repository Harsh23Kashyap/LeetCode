class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        

        if(dp[i][j]!=-1)
            return dp[i][j];

        int curr=matrix[i][j];
        matrix[i][j]=INT_MIN;
        int bp=0;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k],ny=j+dx[k+1];

            if(nx<0 or ny<0 or nx>=matrix.size() or ny>=matrix[0].size())
                continue;

            if(matrix[nx][ny]>curr){
                // cout<<"Going to "<<nx<<" "<<ny<<endl;
                bp=max(bp,dfs(nx,ny,matrix,dp));
            }

        }
        matrix[i][j]=curr;
        // cout<<" from "<<i<<" "<<j<<" we got "<<1+bp<<endl;
        return dp[i][j]=1+bp;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int bp=0;

 vector<vector<int>> dp(m, vector<int> (n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!=INT_MAX){
                    bp=max(bp,dfs(i,j,matrix,dp));
                    // cout<<i<<" "<<j<<" "<<bp<<endl;
                }
            }
        }
        return bp;
    }
};