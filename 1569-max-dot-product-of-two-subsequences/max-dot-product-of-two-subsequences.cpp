class Solution {
public:
    long long dot(vector<int>& nums1, vector<int>& nums2, int i, int j,   vector<vector<long long >> &dp){
        if(j==nums2.size() or i==nums1.size()){
            return INT_MIN;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        //opton1 nums[i]*nums[j];and increment both
        dp[i][j]=nums1[i]*nums2[j]+dot(nums1,nums2,i+1,j+1,dp);
        dp[i][j]=max(1ll*nums1[i]*nums2[j],dp[i][j]);
        // cout<<dp[i][j]<<endl;
        //option2 nums[i] same j increases
        long long  res2=dot(nums1,nums2,i,j+1,dp);
        // cout<<res2<<endl;
        // if(res2!=INT_MIN){
        //     cout<<res2<<endl;
            dp[i][j]=max(dp[i][j],res2);
        // }

        //option3
        long long  res3=dot(nums1,nums2,i+1,j,dp);
        // cout<<res3<<endl;
        //  if(res3!=INT_MIN)
            dp[i][j]=max(dp[i][j],res3);
        // cout<<dp[i][j]<<" "<<res2<<" "<<res3<<endl;
        return dp[i][j];


    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<long long>> dp(n,vector<long long> (m,-1));

        return dot(nums1,nums2,0,0,dp);
    }
};