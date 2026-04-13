class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int l=start,r=start;
        while(l>=0 or r<nums.size()){ 
            if(l>=0 and nums[l]==target)
                return start-l;
            if(r<nums.size() and nums[r]==target)
                return r-start;

                l--,r++;
        }
        return -1;
    }
};