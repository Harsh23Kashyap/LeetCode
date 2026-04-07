class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, vector<pair<int,int>>> u;

        // cout << "Building graph...\n";
        for(auto it:flights) {
            u[it[0]].push_back({it[1],it[2]});
            // cout << "Edge: " << it[0] << " -> " << it[1] << " cost: " << it[2] << "\n";
        }
        vector<vector<int>> vis(n, vector<int> (k+2,INT_MAX));

priority_queue<
    pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>, 
    greater<>
> pq;
        pq.push({0,{0,src}});
        // cout << "\nInitial push: cost=0, stops=0, city=0\n";

        int fc=INT_MAX;

        while(!pq.empty()){
            auto [cost,rem]=pq.top();
            auto [ck,city]=rem;
            pq.pop();

            // cout << "\nPopped -> cost: " << cost << ", stops: " << ck << ", city: " << city << "\n";

            if(vis[city][ck]<cost) {
                // cout << "Skipping due to visited better state\n";
                continue;
            }

            if(city==dst and ck-1<=k)
            {
                // cout << "Reached destination " << dst << " with cost: " << cost << " and stops: " << ck << "\n";
                fc=min(fc,cost);
                continue;
            }

            if(ck>k) {
                // cout << "Skipping as stops exceeded: " << ck << "\n";
                continue;
            }

            for(auto it:u[city]){
                int ncity=it.first;
                int ncost=it.second;

                // cout << "  Exploring -> next city: " << ncity << ", edge cost: " << ncost << "\n";

                if(ncost+cost<vis[ncity][ck+1])
                {
                    vis[ncity][ck+1]=ncost+cost; 
                    pq.push({ncost+cost,{ck+1,ncity}}); 
                }  
            }

        }

        cout << "\nFinal cheapest cost: " << fc << "\n";
        return fc==INT_MAX?-1:fc;
    }
};