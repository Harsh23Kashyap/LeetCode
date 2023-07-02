class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum=accumulate(nums.begin(),nums.end(),0);
        int lsum=0;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            rsum-=nums[i];
            ans[i]=abs(lsum-rsum);
            lsum+=nums[i];
        }
        return ans;
        
    }
};