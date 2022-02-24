class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        vector<int>prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            prefix.push_back(nums[i]+prefix[i-1]);
        }
        int m=*min_element(prefix.begin(),prefix.end());
        if(m<=0)
        return abs(m)+1;
        return 1;
    }
};