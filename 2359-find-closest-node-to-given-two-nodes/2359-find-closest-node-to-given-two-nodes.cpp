class Solution {
public:
    void dfs(vector<int> &v,int node,vector<int> &dist)
    {
        int step=0,n=v.size();
        vector<bool> vis(n,false);
        while(node!=-1 && !vis[node])
        {
            dist[node]=step++;
            vis[node]=true;
            node=v[node];
        }
    }
    int closestMeetingNode(vector<int>& v, int node1, int node2) 
    {
        int n=v.size();
        vector<int> dist1(n,1e9),dist2(n,1e9);
        dfs(v,node1,dist1);
        dfs(v,node2,dist2);
        int dist=1e9,ans=-1;
        for(int i=0;i<n;i++)
        {
            if(max(dist1[i],dist2[i])<dist)
            {
                dist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
        
    }
};