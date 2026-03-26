class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<long long, vector<pair<int, int>>> u;
        vector<long long> rs(m, 0), cs(n, 0);
        long long total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                u[grid[i][j]].push_back({i, j});
                total += grid[i][j];
                rs[i] += grid[i][j];
                cs[j] += grid[i][j];
            }
        }

        // 🔹 Horizontal cuts
        long long top = 0;
        for (int i = 0; i < m - 1; i++) {
            top += rs[i];
            long long bottom = total - top;
            if (top == bottom) return true;

            long long diff = abs(top - bottom);
            if (u.count(diff)) {
                for (auto& c : u[diff]) {
                    bool inTop = (c.first <= i);
                    if ((top > bottom && inTop) || (bottom > top && !inTop)) {
                        int h = inTop ? (i + 1) : (m - 1 - i);
                        // Rule: 2D block stays connected. 1D needs endpoints.
                        if (n > 1 && h > 1) return true;
                        if (n == 1 && (c.first == (inTop ? 0 : i + 1) || c.first == (inTop ? i : m - 1))) return true;
                        if (h == 1 && (c.second == 0 || c.second == n - 1)) return true;
                    }
                }
            }
        }

        // 🔹 Vertical cuts
        long long left = 0;
        for (int j = 0; j < n - 1; j++) {
            left += cs[j];
            long long right = total - left;
            if (left == right) return true;

            long long diff = abs(left - right);
            if (u.count(diff)) {
                for (auto& c : u[diff]) {
                    bool inLeft = (c.second <= j);
                    if ((left > right && inLeft) || (right > left && !inLeft)) {
                        int w = inLeft ? (j + 1) : (n - 1 - j);
                        // Rule: 2D block stays connected. 1D needs endpoints.
                        if (m > 1 && w > 1) return true;
                        if (m == 1 && (c.second == (inLeft ? 0 : j + 1) || c.second == (inLeft ? j : n - 1))) return true;
                        if (w == 1 && (c.first == 0 || c.first == m - 1)) return true;
                    }
                }
            }
        }
        return false;
    }
};