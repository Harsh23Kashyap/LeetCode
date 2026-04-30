class Solution {
public:
vector<int> dx={-1,0,1,0,-1};
    int pass(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int i, int j, int ck){
        if(ck<0)
            return -1e9;
        if(i==grid.size()-1 and j==grid[0].size()-1){
            // cout<<"Returning 0"<<endl;
        return 0;
        }
        if(dp[i][j][ck]!=INT_MIN)
            return dp[i][j][ck];
        int best=-1e9;
        //right
        if(j+1<grid[0].size()){
            if(grid[i][j+1]!=0){
                int save=pass(grid,dp,i,j+1,ck-1);
                if(save!=-1e9)
                best=max(best,grid[i][j+1]+save);
            }
            else{
                int save=pass(grid,dp,i,j+1,ck);
                if(save!=-1e9)
                best=max(best,grid[i][j+1]+save);
                
            }

        }
        if(i+1<grid.size()){
            if(grid[i+1][j]!=0){
                int save=pass(grid,dp,i+1,j,ck-1);
                if(save!=-1e9)
                best=max(best,grid[i+1][j]+save);
            }
            else{
                 int save=pass(grid,dp,i+1,j,ck);
                if(save!=-1e9)
                best=max(best,grid[i+1][j]+save);
            }

        }
        // cout<<i<<" "<<j<<" "<<ck<<" "<<dp[i][j][ck]<<endl;
        return dp[i][j][ck]=best;

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>> (grid[0].size(), vector<int> (k+1,INT_MIN)));
        int ans=0;
        if(grid[0][0]!=0)
            ans=pass(grid,dp,0,0,k-1);
        else
        ans=pass(grid,dp,0,0,k);
        return ans==-1e9?-1:ans;
    }
};