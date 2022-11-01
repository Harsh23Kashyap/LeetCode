class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            int start=i;
            int next=-1;
            for(int j=0;j<m;j++)
            {
                next=start+grid[j][start];
                if(next<0 or next>=n or grid[j][start]!=grid[j][next])
                {
                    start=-1;
                    break;
                }
                else
                {
                    start=next;
                }
            }
            ans[i]=start;
        }
        return ans;
        
    }
};