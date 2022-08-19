class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int> am;
        unordered_map<int,int> vm;
        for(int i:nums)
            am[i]++;
        
        for(int i=0;i<nums.size();i++)
        {
            if(am[nums[i]]<=0)
                continue;
            else if(am[nums[i]]>0 and vm[nums[i]]>0)
            {
                vm[nums[i]]--;
                am[nums[i]]--;
                vm[nums[i]+1]++;
            }
            else if(am[nums[i]]>0 and am[nums[i]+1]>0 and am[nums[i]+2]>0)
            {
                am[nums[i]]--;
                am[nums[i]+1]--;
                am[nums[i]+2]--;
                vm[nums[i]+3]++;
            }
            else
                return false;
        }
        return true;
        
    }
};