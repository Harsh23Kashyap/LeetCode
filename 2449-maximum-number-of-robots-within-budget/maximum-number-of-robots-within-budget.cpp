class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {

        int n = chargeTimes.size();
        deque<int> dq;   // store indices
        long long sum = 0;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {

            // maintain monotonic decreasing deque
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r])
                dq.pop_back();

            dq.push_back(r);

            sum += runningCosts[r];

            // shrink window if cost exceeds budget
            while (!dq.empty() &&
                   (long long)chargeTimes[dq.front()] +
                   (long long)(r - l + 1) * sum > budget) {

                if (dq.front() == l)
                    dq.pop_front();

                sum -= runningCosts[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
