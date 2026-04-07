class Solution {
public:
int ans=0;
unordered_set<int> vis;

void dfs(unordered_map<int,vector<pair<int,int>>> &u, int node, int n){
    // cout << "DFS at node: " << node << ", vis size: " << vis.size() << ", ans: " << ans << "\n";

    if(vis.size()==n){
        // cout << "All nodes visited in DFS, returning\n";
        return;
    }

    for(auto it:u[node]){
        // cout << "  Exploring edge " << node << " -> " << it.first 
        //      << " with cost: " << it.second << "\n";

        if(vis.find(it.first)==vis.end()){
            // cout << "    Visiting new node: " << it.first << "\n";

            vis.insert(it.first);
            ans+=it.second;

            // cout << "    Updated ans: " << ans << "\n";

            dfs(u,it.first,n);
        } 
    }
}

vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

    unordered_map<int,vector<pair<int,int>>> u;

    // cout << "Building graph...\n";
    for(auto it:edges)
    {
        // cout << "Edge: " << it[0] << " -> " << it[1] << "\n";

        u[it[0]].push_back({it[1],0});
        u[it[1]].push_back({it[0],1});
    }

    // // cout << "\nAdj list:\n";
    // for(auto &p : u){
    //     // cout << p.first << ": ";
    //     // for(auto &ne : p.second){
    //     //     // cout << "(" << ne.first << "," << ne.second << ") ";
    //     // }
    //     // // cout << "\n";
    // }

    // cout << "\n--- DFS START ---\n";
    vis.insert(0);
    dfs(u,0,n);
    // cout << "--- DFS END --- ans = " << ans << "\n\n";

    vis.clear();
    vector<int> res(n,0);
    res[0]=ans;

    queue<int> q;
    q.push(0);
    vis.insert(0);

    // cout << "--- BFS START ---\n";

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        // cout << "\nProcessing node: " << it << ", current ans: " << ans << "\n";

        for(auto ne:u[it]){
            // cout << "  Checking neighbor: " << ne.first 
            //      << " cost: " << ne.second << "\n";

            if(vis.find(ne.first)!=vis.end()){
                // cout << "    Already visited, skipping\n";
                continue;
            }

            int old_ans = ans;
            ans=(ne.second==1)?res[it]-1:res[it]+1;

            // cout << "    ans updated from " << old_ans << " -> " << ans << "\n";

            res[ne.first]=ans;
            // cout << "    res[" << ne.first << "] = " << ans << "\n";

            q.push(ne.first);
            vis.insert(ne.first);

            // cout << "    pushed " << ne.first << " to queue\n";
        }
    }

    // cout << "\n--- BFS END ---\n";

    // cout << "\nFinal result:\n";
    // for(int i=0;i<n;i++){
    //     cout << "res[" << i << "] = " << res[i] << "\n";
    // }

    return res;
}
};