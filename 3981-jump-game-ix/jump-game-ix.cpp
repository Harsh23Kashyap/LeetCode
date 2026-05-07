class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefMax(n);
 
        prefMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        vector<int> ans(n);
 
        ans[n - 1] = prefMax[n - 1];

        // running suffix minimum
        int sufMin = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            // component continues
            if (prefMax[i] > sufMin) {
                ans[i] = ans[i + 1];
            }
            else {
                ans[i] = prefMax[i];
            }

            sufMin = min(sufMin, nums[i]);
        }

        return ans;
    }
};