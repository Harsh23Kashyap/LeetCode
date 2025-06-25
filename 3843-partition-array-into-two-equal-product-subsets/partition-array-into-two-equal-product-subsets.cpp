class Solution {
public:
    bool recursive(vector<int>& nums, long long target, int i, __int128 prod, int inc, vector<bool>& vis) {
        if (prod > target) return false;

        if (prod == target) {
            if (inc == nums.size()) return false; // Cannot use full array

            __int128 sec = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (!vis[j]) {
                    sec *= nums[j];
                    if (sec > target) return false;
                }
            }
            return sec == target;
        }

        if (i >= nums.size()) return false;

        // include nums[i]
        vis[i] = true;
        if (recursive(nums, target, i + 1, prod * nums[i], inc + 1, vis)) return true;

        // exclude nums[i]
        vis[i] = false;
        if (recursive(nums, target, i + 1, prod, inc, vis)) return true;

        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if (nums.size() <= 1) return false;
        vector<bool> vis(nums.size(), false);
        return recursive(nums, target, 0, 1, 0, vis);
    }
};
