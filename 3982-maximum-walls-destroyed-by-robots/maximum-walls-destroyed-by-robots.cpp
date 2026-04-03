class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // Sort walls so we can use binary search on them
        sort(walls.begin(), walls.end());

        int n = robots.size();
        vector<pair<int, int>> rr(n);
        for(int i = 0; i < n; i++) {
            rr[i] = {robots[i], distance[i]};
        }
        
        // Sort robots by position
        sort(rr.begin(), rr.end());

        vector<int> L(n), R(n);
        for(int i = 0; i < n; i++) {
            // Left reach: stops exactly AT the previous robot's position
            L[i] = rr[i].first - rr[i].second;
            if(i > 0) L[i] = max(L[i], rr[i-1].first);
            
            // Right reach: stops exactly AT the next robot's position
            R[i] = rr[i].first + rr[i].second;
            if(i < n - 1) R[i] = min(R[i], rr[i+1].first);
        }

        // Helper lambda to safely count walls in the inclusive range [left_bound, right_bound]
        auto count_walls = [&](int left_bound, int right_bound) {
            if (left_bound > right_bound) return 0; // Invalid/Empty interval
            
            auto it1 = lower_bound(walls.begin(), walls.end(), left_bound);
            auto it2 = upper_bound(walls.begin(), walls.end(), right_bound);
            
            return (int)std::distance(it1, it2);
        };

        // dp[i][0] = max walls destroyed up to robot i, if robot i shoots LEFT
        // dp[i][1] = max walls destroyed up to robot i, if robot i shoots RIGHT
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Base cases for the first robot
        dp[0][0] = count_walls(L[0], rr[0].first);
        dp[0][1] = count_walls(rr[0].first, R[0]);

        for(int i = 1; i < n; i++) {
            int walls_left = count_walls(L[i], rr[i].first);
            int walls_right = count_walls(rr[i].first, R[i]);

            // === DP[i][0]: Robot i shoots LEFT ===
            // Option 1: prev shoots Left. Overlap is exactly [L[i], rr[i-1].first]
            int opt1 = dp[i-1][0] + walls_left - count_walls(L[i], rr[i-1].first);
            // Option 2: prev shoots Right. Overlap is exactly [L[i], R[i-1]]
            int opt2 = dp[i-1][1] + walls_left - count_walls(L[i], R[i-1]);
            
            dp[i][0] = max(opt1, opt2);

            // === DP[i][1]: Robot i shoots RIGHT ===
            // Option 3: prev shoots Left. No possible overlap since pos_i > pos_{i-1}
            int opt3 = dp[i-1][0] + walls_right;
            // Option 4: prev shoots Right. Overlap is exactly [rr[i].first, R[i-1]]
            int opt4 = dp[i-1][1] + walls_right - count_walls(rr[i].first, R[i-1]);
            
            dp[i][1] = max(opt3, opt4);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};