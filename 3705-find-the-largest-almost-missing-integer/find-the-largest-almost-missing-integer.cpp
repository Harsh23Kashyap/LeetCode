class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int i = 0; i <= n - k; ++i) 
        {
            unordered_set<int> unique_in_subarray;
            for (int j = i; j < i + k; ++j) {
                unique_in_subarray.insert(nums[j]);
            }
            for (int x : unique_in_subarray) {
                count[x]++;
            }
        }
        int max_val = -1;
        for (auto const& [val, freq] : count) {
            if (freq == 1) {
                max_val = max(max_val, val);
            }
        }
        return max_val; 
    }
};