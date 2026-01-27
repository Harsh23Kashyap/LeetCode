class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, int> sz;

    string find(string x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(string x, string y) {
        string px = find(x);
        string py = find(y);
        if (px == py) return;

        if (sz[px] < sz[py]) swap(px, py);
        parent[py] = px;
        sz[px] += sz[py];
    }

    int removeStones(vector<vector<int>>& stones) {
 
        for (auto s : stones) {
            string k = to_string(s[0]) + "," + to_string(s[1]);
            parent[k] = k;
            sz[k] = 1;
        }
 
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {

                    string a = to_string(stones[i][0]) + "," + to_string(stones[i][1]);
                    string b = to_string(stones[j][0]) + "," + to_string(stones[j][1]);
                    unite(a, b);
                }
            }
        }

        // count components
        unordered_set<string> comps;
        for (auto s : stones) {
            string k = to_string(s[0]) + "," + to_string(s[1]);
            comps.insert(find(k));
        }

        return stones.size() - comps.size();
    }
};
