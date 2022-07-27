class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        
        while(nums.size()!=1)
        {
            bool mini=true;
            vector<int> ans;
            for(int i=0;i<nums.size();i+=2)
            {
                
                if(mini)
                    ans.push_back(min(nums[i],nums[i+1]));
                else
                    ans.push_back(max(nums[i],nums[i+1]));
                mini=!mini;
            }
            nums.clear();
            nums=ans;
            
        }
        return nums[0];
        
    }
};