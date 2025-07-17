class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        vector<vector<int>> dp(nums.size(), vector<int> (k+1,1));
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int rem=(nums[i]+nums[j])%k;
                dp[j][rem]=max(dp[j][rem],dp[i][rem]+1);
                ans=max(ans, dp[j][rem]);
            }
        }
        return ans;

    }
};