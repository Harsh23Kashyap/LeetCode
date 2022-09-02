class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
        {
            dp[i][0]=grid[i][0];
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i][j-1]+grid[i][j];
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=1;
                int x=i,yl=j,yr=j;
                while(x<m and yl>=0 and yr<n)
                {
                    int one=dp[x][yr]-((yl-1<0)?0:dp[x][yl-1]);
                    if(one==cnt)
                    {
                        if(cnt!=1)
                            ans++;
                        cnt+=2;
                    }
                    else
                        break;
                    
                    x++,yl--,yr++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=1;
                int x=i,yl=j,yr=j;
                while(x>=0 and yl>=0 and yr<n)
                {
                    int one=dp[x][yr]-((yl-1<0)?0:dp[x][yl-1]);
                    if(one==cnt)
                    {
                        if(cnt!=1)
                            ans++;
                        cnt+=2;
                    }
                    else
                        break;
                    
                    x--,yl--,yr++;
                }
            }
        }
        return ans;
    }
};