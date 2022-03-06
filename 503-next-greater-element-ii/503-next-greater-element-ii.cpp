class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int mx=INT_MIN;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    mx=nums[j];
                    break;
                }
            }
            if(mx==INT_MIN)
            {
                for(int j=0;j<i;j++)
                {
                    if(nums[j]>nums[i])
                    {
                        mx=nums[j];
                        break;
                    }
                }
            }
            if(mx==INT_MIN)
                ans.push_back(-1);
            else
                ans.push_back(mx);
            
        }
        return ans;
        
    }
};