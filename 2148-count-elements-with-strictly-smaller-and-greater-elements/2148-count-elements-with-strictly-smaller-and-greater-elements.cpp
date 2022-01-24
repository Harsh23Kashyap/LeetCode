class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        if(nums.size()<=2) return 0;
        sort(nums.begin(),nums.end());
        int smallind=1;
        while(nums[smallind]==nums[0] and smallind!=nums.size())
            smallind++;
        int largeind=nums.size()-2;
        while(nums[largeind]==nums[nums.size()-1] and largeind!=0)
            largeind--;
        if(smallind!=nums.size() and largeind!=0)
            return largeind-smallind+1;
        return 0;
    }
};