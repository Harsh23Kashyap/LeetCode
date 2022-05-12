class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        
        
        int c=0;
        int left=0,right=0;
        long long prod=1;
        while(right<nums.size())
        {
            prod*=nums[right];
            // cout<<left<<","<<right<<endl;
            // cout<<prod<<endl;
            if(prod<k)
            {
                c+=right-left+1;
            }
            else
            {
                while(left<=right and prod>=k)
                    prod/=nums[left++];
                
                c+=right-left+1;
            }
            right++;
        }
        return c;
        
    }
};