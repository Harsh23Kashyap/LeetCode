class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int rsum=accumulate(nums.begin(),nums.end(),0);
        int lsum=0;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            rsum-=nums[i];
            ans[i]=abs(lsum-rsum);
            if(ans[i]==0)
                return i;
            lsum+=nums[i];
        }
        return -1;
        
    }
};