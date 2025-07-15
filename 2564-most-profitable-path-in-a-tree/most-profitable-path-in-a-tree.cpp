class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        visited.assign(n, false);
        int t = 0;
        int maxProfit = INT_MIN;

        // Build graph/tree
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Get Bob’s arrival time to each node
        findBobPath(bob, 0);

        // Alice BFS
        queue<pair<int, int>> q;
        unordered_set<int> visAlice;
        int initialReward = amount[0];

        if (bobPath[0] == 0) initialReward /= 2;

        q.push({0, initialReward});
        visAlice.insert(0);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [currNode, currReward] = q.front();
                q.pop();

                int childCount = 0;
                for (int neighbor : tree[currNode]) {
                    if (visAlice.count(neighbor)) continue;

                    int reward = amount[neighbor];
                    if (bobPath.count(neighbor)) {
                        if (bobPath[neighbor] == t + 1)
                            reward /= 2;
                        else if (bobPath[neighbor] < t + 1)
                            reward = 0;
                    }

                    visAlice.insert(neighbor);
                    q.push({neighbor, currReward + reward});
                    childCount++;
                }

                // Leaf node
                if (childCount == 0) {
                    maxProfit = max(maxProfit, currReward);
                }
            }
            t++;
        }

        return maxProfit;
    }

private:
    vector<vector<int>> tree;
    unordered_map<int, int> bobPath;
    vector<bool> visited;

    // DFS from bob to node 0 to record arrival times
    bool findBobPath(int node, int time) {
        visited[node] = true;
        bobPath[node] = time;

        if (node == 0) return true;

        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                if (findBobPath(neighbor, time + 1)) return true;
            }
        }

        bobPath.erase(node);  // backtrack
        return false;
    }
};
