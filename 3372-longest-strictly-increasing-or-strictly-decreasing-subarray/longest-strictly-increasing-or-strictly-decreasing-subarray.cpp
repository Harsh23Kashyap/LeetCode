class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int lmax=1;
        int lmin=1;
        int cmax=1,cmin=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]){
                cmax++;
                lmax=max(cmax,lmax);
            }
            else{
                cmax=1;
            }
            if(nums[i]>nums[i+1]){
                cmin++;
                lmin=max(lmin,cmin);
            }
            else{
                cmin=1;
            }
        }

        return max(lmax,lmin);
    }
};