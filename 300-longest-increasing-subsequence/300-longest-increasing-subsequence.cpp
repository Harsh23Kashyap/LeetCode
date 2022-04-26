class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(ans[ans.size()-1]<nums[i])
            {
                //cout<<ans[ans.size()-1]<<endl;
                ans.push_back(nums[i]);
            }
            else
            {
                auto pos=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[pos]=nums[i];
            }
                
        }
        return ans.size();
        
    }
};