class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        vector<int> dups(nums.begin()+1,nums.end());
        sort(dups.begin(),dups.end());

        return nums[0]+dups[0]+dups[1];
    }
};