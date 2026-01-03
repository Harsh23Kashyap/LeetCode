class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<int>> states;
    vector<vector<int>> compat;
    int n;

    void genStates(vector<int>& curr, int idx) {
        if (idx == n) {
            states.push_back(curr);
            return;
        }
        for (int c = 0; c < 3; c++) {
            if (idx > 0 && curr[idx - 1] == c) continue;
            curr[idx] = c;
            genStates(curr, idx + 1);
        }
    }

    bool compatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        // 🔥 CRITICAL FIX
        if (n > m) swap(n, m);
        this->n = n;

        // 1️⃣ Generate valid row states
        vector<int> curr(n);
        genStates(curr, 0);
        int S = states.size();

        // 2️⃣ Precompute compatibility
        compat.assign(S, {});
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                if (compatible(states[i], states[j])) {
                    compat[i].push_back(j);
                }
            }
        }

        // 3️⃣ DP
        vector<long long> dp_prev(S, 1), dp_cur(S);

        for (int row = 1; row < m; row++) {
            fill(dp_cur.begin(), dp_cur.end(), 0);
            for (int i = 0; i < S; i++) {
                for (int j : compat[i]) {
                    dp_cur[i] = (dp_cur[i] + dp_prev[j]) % MOD;
                }
            }
            dp_prev.swap(dp_cur);
        }

        // 4️⃣ Sum result
        long long ans = 0;
        for (long long x : dp_prev) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};
