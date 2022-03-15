class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int series=0,best=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
                series++;
            else
            {
                best=max(best,series);
                series=0;
            }
        }
        
        return max(best,series);
    }
};