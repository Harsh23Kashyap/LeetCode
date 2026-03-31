class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(m==0){
                if(nums[m]!=nums[m+1])
                    return nums[m];
            }
            else if(m==nums.size()-1){
                if(nums[m]!=nums[m-1])
                    return nums[m];
            }
            else{
                 if(nums[m]!=nums[m-1] and nums[m]!=nums[m+1])
                    return nums[m];
            }

            if(m%2==0){
                if(m+1<nums.size() and nums[m]==nums[m+1])
                l=m+1;
                else
                h=m-1;
               

            }
            else {
                if(nums[m]==nums[m-1])
                l=m+1;
                else
                h=m-1;
               

            }
        }
        return -1;
    }
};