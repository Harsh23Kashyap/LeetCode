class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    dsu.unionSet(i, j);
                }
            }
        }

        return dsu.count;
    }

private:
    class DSU {
        public:
        vector<int> parent, rank;
        int count;

    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            count = n;
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]); // Path compression
            return parent[x];
        }

        void unionSet(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;

            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }

            count--;
        }

       
    };
};
