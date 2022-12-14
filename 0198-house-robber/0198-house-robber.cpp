class Solution {
public:
    int rob(vector<int>& nums) 
    {
        
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        for(int i=2;i<n;i++)
            nums[i]+=*max_element(nums.begin(),nums.begin()+i-1);
        
        
        return *max_element(nums.begin(),nums.end());
    }
};