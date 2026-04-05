class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        if(n==2)
            return nums[0]>nums[1]?0:1;
        int l=0,h=nums.size()-1;

        while(l<=h){
            int m=l+(h-l)/2;
            long long prev=(m==0)?LLONG_MIN:nums[m-1];
            long long nex=(m==n-1)?LLONG_MIN:nums[m+1];
            if(nums[m]>prev and nums[m]>nex)
                return m;
            
            else if(nums[m]>=prev and nums[m]<=nex)
                l=m+1;
           else
                h=m-1;
        }
        return -1;
        
    }
};