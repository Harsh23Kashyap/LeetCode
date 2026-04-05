class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //basic is linear seach;
        for(int i=0;i<nums.size();i++){
            long long prev=(i==0)?LLONG_MIN:nums[i-1];
            long long nex=(i==nums.size()-1)?LLONG_MIN:nums[i+1];
            if(nums[i]>prev and nums[i]>nex)
                return i;

        }
        return -1;
    }
};