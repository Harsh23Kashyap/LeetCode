class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int i,j,m = v.size(),n = v[0].size();
        vector<vector<int>> g(m,vector<int>(n,0));
       
        g[0][0] = 1;
        
        for(i = 0 ; i < m ; i++)
        {
            for(j = 0 ; j < n ; j++)
            {
                if(v[i][j] == 1)
                {
                    g[i][j] = 0;
                }
                else
                {
                    
                    if(i == 0 && j > 0)
                        g[i][j] = g[i][j-1];
                    
                    else if(j == 0 && i > 0)
                        g[i][j] = g[i-1][j];
                    
                    else if(i > 0 && j > 0)
                        g[i][j] = g[i-1][j] + g[i][j-1];
                    
                }
            }
        }
        
        
        return g[m-1][n-1];
        
    }
};