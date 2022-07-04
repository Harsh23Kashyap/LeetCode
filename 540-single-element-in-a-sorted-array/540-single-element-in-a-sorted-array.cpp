class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int low=0,high=nums.size()-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid%2!=0)
            {
                if(mid>=0 and nums[mid-1]!=nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(mid<nums.size() and nums[mid+1]!=nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
            }
        }
       
        
    }
         return nums[low];
    }
        
};