class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> zero;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zero.push_back(i);
        }

        vector<int> dp(s.size(), -1);
        dp[0] = 1;

        int next = 1; // zero[0] is 0 already processed/known

        for (int i = 0; i < zero.size(); i++) {
            if (dp[zero[i]] == -1) continue;

            int mini = zero[i] + minJump;
            int maxi = min((int)s.size() - 1, zero[i] + maxJump);

            int j = lower_bound(zero.begin() + next, zero.end(), mini) - zero.begin();

            while (j < zero.size() && zero[j] <= maxi) {
                dp[zero[j]] = 1;

                if (zero[j] == s.size() - 1)
                    return true;

                j++;
            }

            next = max(next, j); // skip already marked zeros forever
        }

        return dp[s.size() - 1] == 1;
    }
};