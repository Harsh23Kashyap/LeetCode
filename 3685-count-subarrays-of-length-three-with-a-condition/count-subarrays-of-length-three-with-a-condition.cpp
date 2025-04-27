class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<=nums.size()-3;i++){
            // cout<<(nums[i]+nums[i+2])*2.0<<endl;
            if((nums[i]+nums[i+2])*2.0==1.0*nums[i+1])
                sum++;
        }
        return sum;
    }
};