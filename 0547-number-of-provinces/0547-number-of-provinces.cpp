class Solution {
public:
    void dfs(int i, vector<vector<int>>& c, vector<int>& vis)
    {
        for(int j=0;j<c[i].size();j++)
        {
            if(j!=i and c[i][j]==1 and vis[j]==0)
            {
                vis[j]=1;
                dfs(j,c,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        
        vector<int> vis(c.size(),0);
        int a=0;
        for(int i=0;i<c.size();i++)
        {
            if(vis[i]==0)
            {
                a++;
                vis[i]==1;
                dfs(i,c,vis);
            }
        }
        return a;
    }
};