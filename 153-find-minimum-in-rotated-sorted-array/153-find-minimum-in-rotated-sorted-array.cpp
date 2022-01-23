class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int start=0;
        if(nums.size()==1) return nums[0];
        int end=nums.size()-1;
        if(nums[0]<nums[end]) return nums[0];
        //int mini=INT_MAX;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(nums[mid-1]>nums[mid]) return nums[mid];
            if(nums[mid]>nums[0])
                start=mid+1;
            else end=mid-1;
        }
        return -1;
        
    }
};