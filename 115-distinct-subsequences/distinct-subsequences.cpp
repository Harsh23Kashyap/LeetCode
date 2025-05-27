#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solve(const string& s, const string& t, int i, int j) {
        if (j == t.size()) 
        return 1;
        if (i == s.size()) 
        return 0;

        if (dp[i][j] != -1) 
        return dp[i][j];

        int ans = 0;
        if (s[i] == t[j]) {
            ans += solve(s, t, i + 1, j + 1); 
        }
        ans += solve(s, t, i + 1, j);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;

        dp.resize(s.size(), vector<int>(t.size(), -1));
        return solve(s, t, 0, 0);
    }
};
