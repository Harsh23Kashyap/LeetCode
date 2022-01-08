class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> m(nums.size(),0);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        
        m[0]=nums[0];
        m[1]=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            auto it=max_element(m.begin(),m.begin()+i-1);
            m[i]=m[i]+(*it)+nums[i];
        }
        auto maxi= max_element(m.begin(),m.end());
        return *maxi;
    }
    
};