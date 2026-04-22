class Solution {
public:

    int count = 0;
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
 
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];

            for (int j = 0; j < n; j++) 
            {
                if (i == j) 
                continue;

                long long x2 = bombs[j][0], y2 = bombs[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if (dx*dx + dy*dy <= r1*r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
 
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false); 
            count=0;
            dfs(i,adj,visited);
            ans = max(ans, count);
        }

        return ans;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) { 
        visited[node] = true;
        count++;
        for (int nei : adj[node]) {
            if (!visited[nei]) { 
                dfs(nei, adj, visited);
            }
        }

    }
};