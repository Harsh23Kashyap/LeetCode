#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);

        if (total % 2 != 0) 
            return false;

        int target = total / 2;
        memo = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, nums, target);
    }

    bool dfs(int i, int currSum, vector<int>& nums, int target) {
        if (currSum == target) 
            return true;
        if (i >= nums.size() or currSum > target) 
            return false;

        if (memo[i][currSum] != -1) 
            return memo[i][currSum];

        bool skip = dfs(i + 1, currSum, nums, target);
        skip  =  skip or dfs(i + 1, currSum + nums[i], nums, target);

        return memo[i][currSum] = skip;
    }
};
