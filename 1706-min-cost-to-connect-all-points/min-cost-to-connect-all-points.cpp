class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> minDist(n, INT_MAX);
        vector<int> vis(n, 0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        pq.push({0, 0});  
        minDist[0] = 0;

        int totalCost = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (vis[u]) 
                continue;

            vis[u] = 1;
            totalCost += cost;

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    // if (dist < minDist[v]) {
                    //     minDist[v] = dist;
                        pq.push({dist, v});
                    // }
                }
            }
        }

        return totalCost;
    }
};