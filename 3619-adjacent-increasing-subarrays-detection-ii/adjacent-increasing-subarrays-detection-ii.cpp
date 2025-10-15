class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev=0,curr=1;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }
            ans=max(ans,min(curr,prev));

            ans=max(ans,curr/2);
        }
        return ans;
    }
};