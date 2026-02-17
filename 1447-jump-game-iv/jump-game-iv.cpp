class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        
        // Build value -> indices map
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> dp(n, -1);   // dp[i] = min steps to reach i
        queue<int> q;

        q.push(0);
        dp[0] = 0;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            int steps = dp[i];

            if(i == n - 1) return steps;

            // 1) i + 1
            if(i + 1 < n && dp[i + 1] == -1) {
                dp[i + 1] = steps + 1;
                q.push(i + 1);
            }

            // 2) i - 1
            if(i - 1 >= 0 && dp[i - 1] == -1) {
                dp[i - 1] = steps + 1;
                q.push(i - 1);
            }

            // 3) Same value jumps
            for(int idx : mp[arr[i]]) {
                if(dp[idx] == -1) {
                    dp[idx] = steps + 1;
                    q.push(idx);
                }
            }

            // 🔥 Important: clear to avoid revisiting
            mp[arr[i]].clear();
        }

        return -1; // should never hit
    }
};
