class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<vector<int>> visited(n, vector<int>(K + 2, INT_MAX));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({0, 0, src});
        visited[src][0] = 0;

        int ans = INT_MAX;

        while(!pq.empty()) 
        {
            auto [cost, stops, node] = pq.top();
            pq.pop();

            if(stops > K + 1) 
                continue; 
            if(node == dst) 
            {
                ans = cost;
                return ans;
            }

            if(cost > visited[node][stops]) 
                continue;

            for(auto &[nei, wt] : adj[node]) 
            {
                if(stops + 1 <= K + 1 and cost + wt < visited[nei][stops + 1]) 
                {
                    visited[nei][stops + 1] = cost + wt;
                    pq.push({cost + wt, stops + 1, nei});
                }
            }
        }

        return -1;
    }
};