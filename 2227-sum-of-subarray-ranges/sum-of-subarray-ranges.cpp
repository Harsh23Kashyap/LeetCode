class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            long long maxi=nums[i];
            long long mini=nums[i];
            for(int j=i+1;j<nums.size();j++){
                maxi=maxi>nums[j]?maxi:nums[j];
                mini=mini<nums[j]?mini:nums[j];
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};