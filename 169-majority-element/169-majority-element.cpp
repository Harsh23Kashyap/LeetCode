class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int count=1,no=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==no)
                count++;
            else
            {
                no=nums[i];
                count=1;
            }
            if(count>nums.size()/2) break;
        }
        return no;
    }
};