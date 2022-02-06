class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int count=0;
        if(nums.size()<3) return nums.size();
        int fast=2,slow=2;
        while(fast<nums.size())
        {
            if(nums[fast]!=nums[slow-2])
                nums[slow++]=nums[fast];
            fast++;
        }
        // for(int i:nums)
        //     cout<<i<<" , ";
        return slow;
        
    }
};