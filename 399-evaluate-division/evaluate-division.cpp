class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> graph;
        unordered_set<string> nodes;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});

            nodes.insert(a);
            nodes.insert(b);
        }

        vector<double> ans;

        // Process queries
        for (auto &q : queries) {
            string num = q[0];
            string denom = q[1];

            // Unknown variable
            if (nodes.find(num) == nodes.end() or nodes.find(denom) == nodes.end()) {
                ans.push_back(-1.0);
                continue;
            }

            // Same variable
            if (num == denom) {
                ans.push_back(1.0);
                continue;
            }

            // BFS
            queue<pair<string,double>> qu;
            unordered_set<string> visited;

            qu.push({num, 1.0});
            visited.insert(num);

            double result = -1.0;

            while (!qu.empty()) {
                auto [curr, prod] = qu.front();
                qu.pop();

                if (curr == denom) {
                    result = prod;
                    break;
                }

                for (auto &nei : graph[curr]) {
                    string nextNode = nei.first;
                    double weight = nei.second;

                    if (!visited.count(nextNode)) {
                        visited.insert(nextNode);
                        qu.push({nextNode, prod * weight});
                    }
                }
            }

            ans.push_back(result);
        }

        return ans;
    }
};
