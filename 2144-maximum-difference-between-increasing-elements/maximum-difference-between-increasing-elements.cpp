class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                    maxi=max(maxi,nums[j]-nums[i]);
            }
        }

        return maxi==0?-1:maxi;
    }
};