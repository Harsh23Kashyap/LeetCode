class Solution {
public:
    int m, n;

    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& d) {
        if (i >= m || j >= n)
            return INT_MAX;  

        if (i == m - 1 and j == n - 1){
            if(d[i][j]>0)
            return 1;
            else
            return d[i][j]*-1+1;  
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = dfs(i + 1, j, d);
        int right = dfs(i, j + 1, d);


        int need = min(down, right);
        //states to consider
        //power needed is -3 and current is 2
        //power needed is 3 and current is 2 ->if both pisitibe the power needed 1
        if(d[i][j]>=0)
        return dp[i][j] = max(1,need-d[i][j]);
        return dp[i][j] = max(1,d[i][j]*-1+need);


        // return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& d) {
        m = d.size();
        n = d[0].size();
        dp.assign(m, vector<int>(n,-1));
        return dfs(0, 0, d);
    }
};
