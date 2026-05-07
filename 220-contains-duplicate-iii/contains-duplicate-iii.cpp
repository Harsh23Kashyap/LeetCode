class Solution {
public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        multiset<long long> ms;

        for(int i = 0; i < nums.size(); i++) {

            long long curr = nums[i];

            long long left =
                curr - valueDiff;

            long long right =
                curr + valueDiff;
 
            auto l = ms.lower_bound(left);
 
            auto r = ms.upper_bound(right);
 
            if(l != r)
                return true;

            ms.insert(curr);

            if(i >= indexDiff) {

                ms.erase(
                    ms.find(nums[i - indexDiff])
                );
            }
        }

        return false;
    }
};