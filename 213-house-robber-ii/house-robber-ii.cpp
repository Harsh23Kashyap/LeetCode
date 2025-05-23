class Solution {
public:
    int rob(vector<int> nums, int i, int l, vector<int> &dp){
        if(i>=l){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int current=0;
        for(int j=i;j<l;j++){
            current=max(nums[j]+rob(nums,j+2,l,dp),current);
        }
        return dp[i]=current;

    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),-1);
        rob(nums,0,nums.size()-1,dp);
        int s=dp[0];
        cout<<s<<endl;
        vector<int> rp(nums.size(),-1);
        rob(nums,1,nums.size(),rp);
        return max(s,rp[1]);
    }

};