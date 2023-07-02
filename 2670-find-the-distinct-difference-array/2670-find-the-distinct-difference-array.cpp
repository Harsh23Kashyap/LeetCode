class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> prefix;
        unordered_map<int,int> suffix;
        int s=0,p=0;
        for(int i=0;i<nums.size();i++)
        {
            if(suffix.find(nums[i])==suffix.end())
                s++;
            suffix[nums[i]]++;
        }
        
        vector<int> ans(nums.size(),0);
        
        for(int i=0;i<nums.size();i++)
        {
            if(suffix[nums[i]]==1)
            {
               s--;
            }
            suffix[nums[i]]--;
            if(prefix.find(nums[i])==prefix.end())
            {
                p++;
                prefix[nums[i]]++;
            }
            ans[i]=p-s;
        }
        return ans;
    }
};