class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        int m=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++)
            m=min(nums[i+k-1]-nums[i],m);
        return m;
        
        
    }
};