class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> dq;  // store indices of zeros
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0)
                dq.push_back(right);

            if (dq.size() > k) {
                left = dq.front() + 1;
                dq.pop_front();
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
