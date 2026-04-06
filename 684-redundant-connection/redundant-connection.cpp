class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }

        int find(int p){
            if(parent[p]==p)
                return p;
            return parent[p]=find(parent[p]);
        }

        bool unite(int a, int b){
            int ra=find(a);
            int rb=find(b);
            if(ra==rb)
            return false;

            if(rank[ra]>rank[rb]){
                rank[ra]+=rank[rb];
                parent[rb]=ra;
            }
           else{
                rank[rb]+=rank[ra];
                parent[ra]=rb;
            }
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       DSU dsu(n+1);
       vector<int> last;
       for(auto it:edges){
        if(!dsu.unite(it[0],it[1]))
            last= it;
       }
       return last;

    }
};