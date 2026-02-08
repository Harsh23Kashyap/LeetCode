class Solution {
public:
int maxi=0;

int pass(vector<vector<int>> &dp, int l, int r,vector<int>& nums){
    if(l<0)
    return 1;
    if(r>nums.size())
    return 1;
    if(l>r)
        return 0;

    //we need to find valid k;
    if(dp[l][r]!=-1)
    return dp[l][r];
    int ans=0;
    for(int k=l+1;k<r;k++){
            //if we chooose some k then l+1 and k-1 is left side
            ans=max(ans, nums[l]*nums[r]*nums[k]+pass(dp,l,k,nums)+pass(dp,k,r,nums));
        
    }
    return dp[l][r]=ans;
}
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1,-1));

        return pass(dp,0,nums.size()-1,nums);
    }
};