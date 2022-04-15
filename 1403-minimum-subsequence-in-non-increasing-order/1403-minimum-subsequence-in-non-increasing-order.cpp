class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        vector<int> res;
        sort(nums.begin(),nums.end(),greater<int>());
        int count=accumulate(nums.begin(),nums.end(),0);
        int lc=0;
        for(int i=0;i<nums.size();i++)
        {
            if(lc+nums[i]>count-nums[i])
            {
                res.push_back(nums[i]);
                count-=nums[i];
                lc+=nums[i];
                break;
            }
            else
            {
                res.push_back(nums[i]);
                count-=nums[i];
                lc+=nums[i];
            }
        }
        return res;
        
    }
};