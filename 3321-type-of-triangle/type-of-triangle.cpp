class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]>=nums[1]+nums[2] or nums[1]>=nums[2]+nums[0] or nums[2]>=nums[1]+nums[0])
        return "none";
        if(nums[0]==nums[1] and nums[1]==nums[2])
        return "equilateral";
        else  if(nums[0]!=nums[1] and nums[1]!=nums[2] and nums[2]!=nums[0])
        return "scalene";
        return "isosceles";
    }
};