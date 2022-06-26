class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxi=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                maxi=max(c,maxi);
                c=0;
                
            }
            else
             c++;
                
        }
        maxi=max(c,maxi);
        return maxi;
        
    }
};