class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
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

        // Horizontal cuts
        long long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            topSum += rs[i];
            long long botSum = total - topSum;
            if (check(topSum, botSum, u, true, i, m, n)) return true;
        }

        // Vertical cuts
        long long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            leftSum += cs[j];
            long long rightSum = total - leftSum;
            if (check(leftSum, rightSum, u, false, j, m, n)) return true;
        }

        return false;
    }

private:
    bool check(long long s1, long long s2, unordered_map<long long, vector<pair<int, int>>>& u, 
               bool isHorizontal, int cutIdx, int m, int n) {
        if (s1 == s2) return true;
        
        long long diff = abs(s1 - s2);
        if (!u.count(diff)) return false;

        for (auto& cell : u[diff]) {
            int r = cell.first, c = cell.second;
            bool inFirstSection = isHorizontal ? (r <= cutIdx) : (c <= cutIdx);
            
            // We must remove the cell from the heavier section
            if ((s1 > s2 && inFirstSection) || (s2 > s1 && !inFirstSection)) {
                // Connectivity Check
                if (isHorizontal) {
                    // Current section is (height rows x n cols)
                    int sectionHeight = inFirstSection ? (cutIdx + 1) : (m - 1 - cutIdx);
                    if (n > 1 && sectionHeight > 1) return true; // 2D block
                    if (n == 1) { // 1D Column
                        if (inFirstSection && (r == 0 || r == cutIdx)) return true;
                        if (!inFirstSection && (r == cutIdx + 1 || r == m - 1)) return true;
                    } else if (sectionHeight == 1) { // 1D Row
                        if (c == 0 || c == n - 1) return true;
                    }
                } else {
                    // Current section is (m rows x width cols)
                    int sectionWidth = inFirstSection ? (cutIdx + 1) : (n - 1 - cutIdx);
                    if (m > 1 && sectionWidth > 1) return true; // 2D block
                    if (m == 1) { // 1D Row
                        if (inFirstSection && (c == 0 || c == cutIdx)) return true;
                        if (!inFirstSection && (c == cutIdx + 1 || c == n - 1)) return true;
                    } else if (sectionWidth == 1) { // 1D Column
                        if (r == 0 || r == m - 1) return true;
                    }
                }
            }
        }
        return false;
    }
};