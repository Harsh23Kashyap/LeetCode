class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int pos;
        bool once=false;
        int i;
        for (i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1] )
            {
                once =true;
                break;
            }
        }
        if(!once) return true;
        //cout<<i+1;
        for(int j=i+1;j<nums.size()-1;j++)
        {
            if(nums[j]>nums[j+1] || nums[j]>nums[0])
                return false;
        }
        if(nums[nums.size()-1]>nums[0]) return false;
        return true;
    }
};