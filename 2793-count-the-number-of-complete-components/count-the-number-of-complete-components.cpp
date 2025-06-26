class Solution {
public:
vector<int> parent, rank;
     int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  
        return parent[x];
    }
        // Union by rank
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        // cout<<"uniting "<<px<<" "<<py<<endl;
        // cout<<rank[px]<<" "<<rank[py]<<endl;
        if (px == py){
            // rank[px]++;
            return false; 
        } 

        if (rank[px] <= rank[py]){
            rank[py]+=rank[px];
            parent[px] = py;
        }
        else if (rank[px] > rank[py]){
            rank[px]+=rank[py];
            parent[py] = px;
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        rank.resize(n, 1); 
        unordered_map<int,vector<int>> ul;

        for(int i=0;i<edges.size();i++){
            ul[edges[i][0]].push_back(edges[i][1]);
            ul[edges[i][1]].push_back(edges[i][0]);
            unite(edges[i][0],edges[i][1]);
        }
        int tc=0;
        unordered_map<int,int> vis;
        for(int i=0;i<n;i++){
            int sz=parent[i];
            int ranking=rank[sz];
            int totaledge=ul[i].size();
            cout<<i<<" "<<sz<<" "<<ranking<<" "<<totaledge<<endl;
            if(totaledge==ranking-1){
                vis[sz]++;
                if(vis[sz]==ranking)
                    tc++;
            }


        }
        return tc;






        
    }
};