class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        sort(nums.begin(),nums.end());
        int mul=original;
        auto it=find(nums.begin(),nums.end(),mul);
        while(it!=nums.end())
        {
            mul*=2;
            it=find(nums.begin(),nums.end(),mul);
        }
        return mul;
    }
};