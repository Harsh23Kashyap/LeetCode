class Solution {
public:
    struct State {
        double time;
        int stage;
        int mask;
        bool atBase;
    };

    struct CompareState {
        bool operator()(const State& a, const State& b) const {
            return a.time > b.time; // min-heap based on time
        }
    };

    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if (k == 1) return (n == 1) ? time[0] * mul[0] : -1.0;

        int fullMask = (1 << n) - 1;
        priority_queue<State, vector<State>, CompareState> pq;
        vector<vector<vector<double>>> dp(1 << n, vector<vector<double>>(m, vector<double>(2, 1e18)));

        pq.push({0.0, 0, fullMask, true});
        dp[fullMask][0][1] = 0.0;

        while (!pq.empty()) {
            auto [currTime, stage, mask, atBase] = pq.top();
            pq.pop();

            if (mask == 0 && !atBase) return currTime;

            if (dp[mask][stage][atBase] < currTime) continue;

            if (atBase) {
                // Generate all subsets (non-empty, up to size k)
                for (int submask = mask; submask; submask = (submask - 1) & mask) {
                    int count = __builtin_popcount(submask);
                    if (count == 0 || count > k) continue;

                    int maxT = 0;
                    for (int i = 0; i < n; ++i) {
                        if ((submask >> i) & 1) {
                            maxT = max(maxT, time[i]);
                        }
                    }

                    double tripTime = maxT * mul[stage];
                    int nextStage = (stage + (int)floor(tripTime)) % m;
                    int newMask = mask ^ submask;

                    if (dp[newMask][nextStage][0] > currTime + tripTime) {
                        dp[newMask][nextStage][0] = currTime + tripTime;
                        pq.push({currTime + tripTime, nextStage, newMask, false});
                    }
                }

            } else {
                // Return one person who already crossed
                for (int i = 0; i < n; ++i) {
                    if (((mask >> i) & 1) == 0) { // crossed
                        int newMask = mask | (1 << i);
                        double returnTime = time[i] * mul[stage];
                        int nextStage = (stage + (int)floor(returnTime)) % m;

                        if (dp[newMask][nextStage][1] > currTime + returnTime) {
                            dp[newMask][nextStage][1] = currTime + returnTime;
                            pq.push({currTime + returnTime, nextStage, newMask, true});
                        }
                    }
                }
            }
        }

        return -1.0;
    }
};
