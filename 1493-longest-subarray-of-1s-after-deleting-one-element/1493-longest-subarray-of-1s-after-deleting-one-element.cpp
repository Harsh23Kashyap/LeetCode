class Solution {
public:
    bool possible(vector<int>& nums, int m)
    {
        int c=0;
        for(int i=0;i<m;i++)
        {
            if(nums[i]==1)
                c++;
        }
        if(c>=m-1)
            return true;
        
        for(int i=m;i<nums.size();i++)
        {
            if(nums[i]==1)
                c++;
            if(nums[i-m]==1)
                c--;
            
            if(c>=m-1)
                return true;
        }
        return false;
    }
    int longestSubarray(vector<int>& nums) {
        int l=1,r=nums.size();
        int ans=1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(possible(nums,m))
            {
                ans=m;
                l=m+1;
            }
            else
                r=m-1;
                
        }
        return ans-1;
        
    }
};