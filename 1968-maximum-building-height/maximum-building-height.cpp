class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        int ans = 0;
        for (int i = 1; i < m; ++i) {
            int l = restrictions[i - 1][0], r = restrictions[i][0];
            int hl = restrictions[i - 1][1], hr = restrictions[i][1];
            ans = max(ans, (r - l + hl + hr) / 2);
        }

        return ans;
    }
};