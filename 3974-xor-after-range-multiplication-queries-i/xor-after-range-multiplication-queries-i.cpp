class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int m=1e9+7;

        for(auto it:queries){
            int l=it[0],r=it[1],k=it[2],v=it[3];
            while(l<=r){
                nums[l]=(1ll*nums[l]*v)%m;
                l+=k;
            }
        }

        int ans=0;
        for(auto it:nums)
            ans=ans^it;
        
        return ans;
    }
};