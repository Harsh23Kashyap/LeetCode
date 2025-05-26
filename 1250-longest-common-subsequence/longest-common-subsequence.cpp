class Solution {
public:
    int longestPossible(vector<vector<int>>& dp, const string &t1, const string &t2, int i, int j) {
        if(i == (int)t1.size() || j == (int)t2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(t1[i] == t2[j])
            ans = 1 + longestPossible(dp, t1, t2, i + 1, j + 1);

        ans = max(ans, longestPossible(dp, t1, t2, i + 1, j));
        ans = max(ans, longestPossible(dp, t1, t2, i, j + 1));

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = (int)text1.size();
        int m = (int)text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return longestPossible(dp, text1, text2, 0, 0);
    }
};
