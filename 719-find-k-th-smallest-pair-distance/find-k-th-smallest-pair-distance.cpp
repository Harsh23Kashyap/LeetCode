class Solution {
public:
    int possible(int m, vector<int>& nums){
        int l=0,r=0;
        int c=0;
        while(r<nums.size()){
            
            while(l<=r and nums[r]-nums[l]>m)
            {
                l++;
            }

            c+=r-l;
            r++;
        }
        return c;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0];
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(possible(m, nums)>=k){
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};