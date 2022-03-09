class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int csum=0;
        int fin=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            csum+=nums[i];
            if(fin<csum)fin=csum;
            if(csum<0)csum=0;
            
        }
        return fin;
    }
};