class Solution {
public:
    int smallestEqual(vector<int>& nums) 
    {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==i%10)
                ans=min(ans,i);
        }
        return ans==INT_MAX?-1:ans;
        
    }
};