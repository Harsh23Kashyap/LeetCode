class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
          int n = nums.size();
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int currMin = nums[i];
            int currMax = nums[i];

            for (int j = i; j < n; j++) {
                currMin = min(currMin, nums[j]);
                currMax = max(currMax, nums[j]);
                total += (currMax - currMin);
            }
        }

        return total;
    }
};