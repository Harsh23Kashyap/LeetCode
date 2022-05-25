class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis(nums.size(),1);
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i] and lis[j]<=lis[i])
                    lis[j]=max(lis[j],lis[i]+1);
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};