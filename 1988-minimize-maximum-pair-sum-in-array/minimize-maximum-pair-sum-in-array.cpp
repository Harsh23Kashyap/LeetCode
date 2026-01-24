class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxi=INT_MIN;

        int i=0,j=nums.size()-1;

        while(i<j){
            maxi=max(maxi,nums[i]+nums[j]);
            i++,j--;
        }
        return maxi;
    }
};