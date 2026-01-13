class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int full=1<<nums1.size();
        vector<int> dp(full,1e9);
        dp[0]=0;

        for(int mask=0;mask<full;mask++){
            int i=__builtin_popcount(mask);
            for(int k=0;k<nums1.size();k++){
                if((mask&(1<<k))==0){
                    int newmask=mask | (1<<k);
                    dp[newmask] = min(dp[newmask], dp[mask] + (nums1[i] ^ nums2[k]));
                }
            }
        }
     return dp[full-1];
    }
};