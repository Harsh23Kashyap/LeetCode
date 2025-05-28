class Solution {
public:
    long long totalCost(const vector<int>& nums, const vector<int>& cost, int x) {
        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += (long long)cost[i] * abs(nums[i] - x);
        }
        return total;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        long long answer = LLONG_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long costMid = totalCost(nums, cost, mid);
            long long costMidPlus = totalCost(nums, cost, mid + 1);

            answer = min(answer, costMid);

            // Move the search space towards lower cost
            if (costMid > costMidPlus) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return answer;
    }
};
