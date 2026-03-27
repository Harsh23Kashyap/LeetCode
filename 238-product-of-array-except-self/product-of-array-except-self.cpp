class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod(nums.size(),1);
        prod[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prod[i]=prod[i-1]*nums[i];
        }
 vector<int>  ans(nums.size(),0);
        int l=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=(i==0)?1:prod[i-1];
            ans[i]*=l;
            l*=nums[i];
        }
        return ans;
    }
};