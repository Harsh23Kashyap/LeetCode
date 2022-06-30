class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int c=0;
        int med=nums[nums.size()/2];
        for(int i:nums)
            c+=abs(i-med);
        
        return c;
    }
};