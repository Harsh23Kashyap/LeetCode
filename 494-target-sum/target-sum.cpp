class Solution {
public:
 int sum=0;
int pass(int i, int currSum, vector<vector<int>> &dp, vector<int>& nums, int target){
    if(i>=nums.size()){
        if(currSum==target){
            return 1;
        }
        else
        return 0;
    }

    if(dp[i][sum+currSum]!=-1)
        return dp[i][sum+currSum];

    //Add
    int cal=pass(i+1,currSum+nums[i],dp,nums,target);

    //Subtract
    cal+=pass(i+1,currSum-nums[i],dp,nums,target);

    return dp[i][sum+currSum]=cal;

}
    int findTargetSumWays(vector<int>& nums, int target) {
       sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1, vector<int> (2*sum+1,-1));
        return pass(0,0,dp, nums ,target);
    }
};