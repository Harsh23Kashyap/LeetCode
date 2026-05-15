class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums[l]<nums[h] or nums.size()==1)
        return nums[l];
        while(l<=h){
            int m=l+(h-l)/2;
            if(m-1>=0 and nums[m-1]>nums[m])
                return nums[m];
            if(m+1<nums.size() and nums[m+1]<nums[m])
                return nums[m+1];
            
            if(nums[m]<nums[h]){
                h=m-1;
            }
            else
            l=m+1;
        }
        return -1;
    }
};