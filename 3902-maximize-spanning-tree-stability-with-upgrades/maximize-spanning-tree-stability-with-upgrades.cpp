class Solution {
public:
    class DSU {
    public:
        int n;
        vector<int> rank, parent;
        DSU(int n_) {
            n = n_;
            rank.assign(n, 1);
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int a) {
            if (parent[a] == a) return a;
            return parent[a] = find(parent[a]);
        }
        bool uni(int a, int b) {
            int x = find(a), y = find(b);
            if (x == y) return false;
            if (rank[x] < rank[y]) {
                rank[y] += rank[x];
                parent[x] = y;
            } else {
                rank[x] += rank[y];
                parent[y] = x;
            }
            return true;
        }
    };

    bool canBuild(int m, vector<vector<int>>& edges, int k, int n) {
        DSU dsu(n);
        int added = 0;
        vector<vector<int>> optional;
        for (int i = 0; i < edges.size(); i++) {
            auto& it = edges[i];
            int u = it[0], v = it[1], s = it[2], must = it[3];
            if (must == 1) {
                if (s < m) return false;
                if (dsu.uni(u, v)) added++;
                else return false;
            } else {
                optional.push_back({s, u, v});
            }
        }
        if (added == n - 1) return true;
        if (added > n - 1) return false;

        sort(optional.rbegin(), optional.rend());

        for (auto& it : optional) {
            int s = it[0], u = it[1], v = it[2];
            if (s >= m) {
                if (dsu.uni(u, v)) added++;
            } else if (k > 0 && s * 2 >= m) {
                if (dsu.uni(u, v)) {
                    k--;
                    added++;
                }
            }
            if (added == n - 1) return true;
        }

        return added == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // ✅ Precheck
        DSU pre(n);
        int mustCount = 0;
        for (auto& e : edges) {
            if (e[3] == 1) {
                mustCount++;
                if (!pre.uni(e[0], e[1])) return -1;
            }
        }
        if (mustCount > n - 1) return -1;

        // ✅ Binary Search
        int low = 0, high = 2e5, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canBuild(mid, edges, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
