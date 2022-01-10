class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = make_pair(nums[i], i);
        }
        sort(arr.begin(), arr.end()); // Sort arr in increasing order by their values.
        int left = 0, right = n- 1;
        while (left < right) {
            int sum2 = arr[left].first + arr[right].first;
            if (sum2 == target) 
                return {arr[left].second, arr[right].second};
            if (sum2 > target)
                right -= 1; // Try to decrease sum2
            else
                left += 1; // Try to increase sum2
        }
        return {};
    }
};