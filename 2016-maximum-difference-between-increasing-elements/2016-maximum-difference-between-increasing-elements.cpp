class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int lower=nums[0];
        int diff=INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            diff=max(diff,nums[i]-lower);
            lower=min(lower,nums[i]);
        }
        if(diff<=0)
            return -1;
        return diff;
    }
};