class Solution {
public:
    const long long NEG_INF = -1e18;

    long long solve(vector<int>& a, vector<int>& b, int i, int j,
                    vector<vector<long long>>& dp) {
        if (i == a.size() || j == b.size())
            return NEG_INF;

        if (dp[i][j] != NEG_INF)
            return dp[i][j];

        long long take =
            max((long long)a[i] * b[j],
                (long long)a[i] * b[j] + solve(a, b, i + 1, j + 1, dp));

        long long skip1 = solve(a, b, i + 1, j, dp);
        long long skip2 = solve(a, b, i, j + 1, dp);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> dp(n, vector<long long>(m, NEG_INF));
        return solve(nums1, nums2, 0, 0, dp);
    }
};
