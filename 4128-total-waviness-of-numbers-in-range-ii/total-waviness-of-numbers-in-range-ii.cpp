class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node memo[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev2, int prev1,
             bool started, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started])
            return memo[pos][prev2][prev1][started];

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node child =
                    dfs(pos + 1, 10, 10, false, ntight);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else if (!started) {

                Node child =
                    dfs(pos + 1, 10, d, true, ntight);

                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else {

                int add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node child =
                    dfs(pos + 1, prev1, d, true, ntight);

                ans.cnt += child.cnt;
                ans.wav += child.wav + child.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            memo[pos][prev2][prev1][started] = ans;
        }

        return ans;
    }

    long long calc(long long x) {
        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};