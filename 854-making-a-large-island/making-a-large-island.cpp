class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b]) 
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        // Step 1: connect all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0 && nj >= 0 && ni < n && nj < n 
                            && grid[ni][nj] == 1) {
                            int u = i * n + j;
                            int v = ni * n + nj;
                            dsu.unite(u, v);
                        }
                    }
                }
            }
        }

        int ans = 0;
        bool hasZero = false;

        // Step 2: try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    hasZero = true;

                    unordered_set<int> parents;
                    
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0 && nj >= 0 && ni < n && nj < n 
                            && grid[ni][nj] == 1) {
                            int p = dsu.find(ni * n + nj);
                            parents.insert(p);
                        }
                    }

                    int total = 1; // flip current 0

                    for (auto p : parents) {
                        total += dsu.size[p];
                    }

                    ans = max(ans, total);
                }
            }
        }

        // Step 3: edge case (all 1s)
        if (!hasZero) return n * n;

        return ans;
    }
};