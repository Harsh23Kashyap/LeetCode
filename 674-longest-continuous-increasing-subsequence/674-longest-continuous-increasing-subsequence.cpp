class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int maxi=1,curr=1,prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                curr++;
            else
                curr=1;
            prev=nums[i];
            maxi=max(maxi,curr);
                
        }
        return maxi;
        
    }
};