class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        return max(maxi-mini-2*k,0);
        
    }
};