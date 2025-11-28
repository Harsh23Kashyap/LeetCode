class Solution {
public:
int c=0;
long long kabs;
vector<int> valuesabs;
// unordered_map<int,int> aggsum;
    long long  dfs(int src, int par, unordered_map<int, vector<int>> &u){
        long long sum=valuesabs[src];
        for(auto it:u[src]){
            if(it==par)
            continue;

            sum+=dfs(it,src,u);

        }
        // aggsum[src]=sum;
        if(sum%kabs==0)
        {
            c++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        valuesabs=values;
        unordered_map<int, vector<int>> u;
    kabs=k;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            u[a].push_back(b);
             u[b].push_back(a);
        }
        dfs(0,-1,u);

        // for(auto it: aggsum)
        // cout<<it.first<<" "<<it.second<<endl;

        return c;
        
    }
};