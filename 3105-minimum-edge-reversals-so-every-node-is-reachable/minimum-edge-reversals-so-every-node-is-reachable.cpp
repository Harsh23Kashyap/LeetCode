class Solution {
public:
int ans=0;
unordered_set<int> vis;
unordered_map<int,vector<pair<int,int>>> u;
void dfs(int node){
   
    for(auto it:u[node]){
         if(vis.find(it.first)!=vis.end())
            continue;
        // cout<<it.first<<" "<<it.second<<endl;
        ans+=it.second;
        vis.insert(it.first);
        dfs(it.first);

    }
}

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        

        for(auto it:edges){
            u[it[0]].push_back({it[1],0});
            u[it[1]].push_back({it[0],1});
        }
        vis.insert(0);
        dfs(0);

 vector<int> res(n,0);
 res[0]=ans;
// cout<<ans<<endl;
    vis.clear();
    vis.insert(0);
    queue<pair<int,int>> q;
    q.push({0,ans});
    while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto ne:u[it.first]){
                // cout<<ne.first<<endl;
                if(vis.find(ne.first)!=vis.end()){
                    continue;
                }
                int cans=it.second;
                cans+=(ne.second==0)?1:-1;
                // cout<<ne.first<<" "<<ne.second<<" "<<ans<<endl;
                res[ne.first]=cans;
                q.push({ne.first,cans});
                vis.insert(ne.first);
            }
        
    }
    return res;

    }
};