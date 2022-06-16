class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        
        int fast=nums[0],slow=nums[0];
       do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        
        slow=nums[0];
        while(slow!=fast)
        {
           slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};