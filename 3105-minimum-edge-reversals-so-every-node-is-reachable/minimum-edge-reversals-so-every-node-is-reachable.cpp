class Solution {
public:
int ans=0;
unordered_set<int> vis;
bool dfs( unordered_map<int,vector<pair<int,int>>> &u, int node, int n){
    if(vis.size()==n)
    return true;

    //i wanna go next;
    for(auto it:u[node]){
        if(vis.find(it.first)==vis.end()){
            vis.insert(it.first);
            ans+=it.second;
           if(dfs(u,it.first,n))
           return true;
        }

    }
    return false;

}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        /*This is the logic is quite simple when you get it. The logic is basically that we first give the value to each edge. For every edge that is in correct order (that is, from u to v), we give it a value of 0 because we don't need to reverse it. For every other edge that is in the opposite direction, we give it a cost of 1 so that we can clearly differentiate between the opposite edge.

Once we have that, we start from any node. Let's say we start from node 0, because we want to find the answer for 0 first. We find all the edges that are opposite and that we have calculated for 0 completely. What we then basically do is we just do a sort of BFS traversal where we look into what other child of 0 we will get; we will basically get one child only because it's sort of a tree. We go there and we see, "Okay, going to this edge, did I have to reverse the edge? If yes, then otherwise the cost will increase by 1." We keep on doing this for all the limits. 
        */
        unordered_map<int,vector<pair<int,int>>> u;

        for(auto it:edges)
        {
            u[it[0]].push_back({it[1],0});
            u[it[1]].push_back({it[0],1});
        }
 
        //lets calculate for 0
        vis.insert(0);
        dfs(u,0,n);
        vis.clear();
        vector<int> res(n,0);
        res[0]=ans;
        queue<int> q;
        q.push(0);
        vis.insert(0);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto ne:u[it]){
                if(vis.find(ne.first)!=vis.end())
                continue;
                ans=(ne.second==1)?res[it]-1:res[it]+1;
                vis.insert(ne.first);
                res[ne.first]=ans;
                q.push(ne.first);
                
            }

        }
        return res;


    }
};