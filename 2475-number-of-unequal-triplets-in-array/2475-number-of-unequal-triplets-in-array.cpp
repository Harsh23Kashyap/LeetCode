class Solution {
public:
    int unequalTriplets(vector<int>& nums) 
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    if(nums[i]!=nums[j] and nums[j]!=nums[k] and nums[i]!=nums[k])
                        c++;
                }
            }
        }
        return c;
    }
};