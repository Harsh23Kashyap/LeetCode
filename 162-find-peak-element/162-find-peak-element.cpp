class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int start =0;
        int end=nums.size()-1;
        if(nums.size()==1 || nums[0]>nums[1]) return 0;
        int mid=0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(mid==0) mid=1;
            if(mid==nums.size()-1) mid=nums.size()-2;
            cout<<" Index- "<<mid<<endl;
            int temp=nums[mid];
            if(temp>nums[mid-1] && temp>nums[mid+1]) return mid;
            else if(temp>nums[mid-1] && temp<nums[mid+1])
                start=mid+1;
            else if(temp<nums[mid-1] && temp>nums[mid+1])
                end=mid-1;
            else 
                end=mid-1;
        }
        return mid;
    }
};