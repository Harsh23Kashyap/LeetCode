class Solution {
public:
    vector<pair<char,long long>> diff;
    long long dp[100005][3];
    int m;

    long long pass(int idx, int ver, string &pattern) {

        if (ver == 3) return 1;
        if (idx >= m) return 0;

        if (dp[idx][ver] != -1)
            return dp[idx][ver];

        long long skip = pass(idx + 1, ver, pattern);
        long long take = 0;

        if (diff[idx].first == pattern[ver]) {
            take = diff[idx].second *
                   pass(idx + 1, ver + 1, pattern);
        }

        return dp[idx][ver] = skip + take;
    }

    long long solvePattern(string pattern) {
        memset(dp, -1, sizeof(dp));
        return pass(0, 0, pattern);
    }

    long long numberOfWays(string s) {

        // build block compression
        int n = s.size();
        int i = 0;

        while (i < n) {
            char c = s[i];
            long long count = 0;
            while (i < n && s[i] == c) {
                count++;
                i++;
            }
            diff.push_back({c, count});
        }

        m = diff.size();

        long long ans = 0;

        ans += solvePattern("010");
        ans += solvePattern("101");

        return ans;
    }
};
