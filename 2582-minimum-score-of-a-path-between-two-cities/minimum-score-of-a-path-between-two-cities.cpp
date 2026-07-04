class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<vector<int>>> u;

        for (int i = 0; i < roads.size(); i++) {
            u[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            u[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> vis(n + 1, INT_MAX / 2);

        vis[1] = INT_MAX / 2;                
        pq.push({INT_MAX / 2, 1});

        int best = INT_MAX;

        while (!pq.empty()) {

            auto kit = pq.top();
            pq.pop();

            int dist = kit[0];
            int stop = kit[1];

            if (dist > vis[stop])            
                continue;

            if (stop == n)
                best = min(best, dist);

            for (auto it : u[stop]) {

                int nstop = it[0];
                int ndist = it[1];

                int newDist = min(ndist, dist);   

                if (vis[nstop] > newDist) {     
                    vis[nstop] = newDist;
                    pq.push({newDist, nstop});
                }
            }
        }

        return best;
    }
};