class Solution {
public:
    vector<int> ans;
    unordered_set<int> vis;
    int n;
    bool found = false;

    void dfs(int idx) {
        if (found) return;

        while (idx < ans.size() && ans[idx] != -1) idx++;  // Skip filled positions
        if (idx == ans.size()) {
            found = true;
            return;
        }

        for (int i = n; i >= 1; i--) {
            if (vis.count(i)) continue;

            if (i == 1) {
                ans[idx] = 1;
                vis.insert(1);
                dfs(idx + 1);
                if (found) return;
                vis.erase(1);
                ans[idx] = -1;
            } else if (idx + i < ans.size() && ans[idx] == -1 && ans[idx + i] == -1) {
                ans[idx] = i;
                ans[idx + i] = i;
                vis.insert(i);
                dfs(idx + 1);
                if (found) return;
                vis.erase(i);
                ans[idx] = ans[idx + i] = -1;
            }
        }
    }

    vector<int> constructDistancedSequence(int no) {
        n = no;
        ans = vector<int>(2 * n - 1, -1);
        dfs(0);
        return ans;
    }
};
