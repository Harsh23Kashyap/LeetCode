class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1])
            return nums[0];
        if(nums.size()==1)
            return nums[0];
        if(n==2)
            return min(nums[0],nums[1]);
        
        int l=0,h=n-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]>nums[m+1])
                return nums[m+1];
            if(nums[m-1]>nums[m])
                return nums[m];
            
            if(nums[0]<nums[m])
                l=m+1;
            else
                h=m-1;
            
        }
        return -1;
        
    }
};