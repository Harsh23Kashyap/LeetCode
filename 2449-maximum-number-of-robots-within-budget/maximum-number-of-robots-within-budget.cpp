class Solution {
public:
    bool possible(vector<int>& ct, vector<int>& rc, long long budget, int k) {
        if (k == 0) return true; // 0 robots always possible

        deque<int> dq; // Stores indices of elements in ct, for finding max in window
        long long current_sum_rc = 0;
        int n = ct.size();
        int left = 0;

        for (int right = 0; right < n; ++right) {
            current_sum_rc += rc[right];

            // Maintain deque for maximum chargeTime in the current window
            while (!dq.empty() && ct[dq.back()] <= ct[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            // Shrink the window if its size exceeds k
            if (right - left + 1 > k) {
                current_sum_rc -= rc[left];
                if (dq.front() == left) { // If the leftmost element was the maximum, remove it
                    dq.pop_front();
                }
                left++;
            }

            // Check cost when window size is k
            if (right - left + 1 == k) {
                long long max_charge_time = ct[dq.front()];
                if (max_charge_time + (long long)k * current_sum_rc <= budget) {
                    return true;
                }
            }
        }
        return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int low = 0, high = n; // Max possible k is n
        int ans = 0; // Initialize ans to 0 for the case where no robots can be run

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(chargeTimes, runningCosts, budget, mid)) {
                ans = mid;
                low = mid + 1; // Try for a larger k
            } else {
                high = mid - 1; // k is too large, try a smaller k
            }
        }
        return ans;
    }
};