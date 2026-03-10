class Solution {
public:
    int maxProduct(vector<int>& nums) {
        

        int a=nums[0],b=nums[0],ans=nums[0];

        for(int i=1;i<nums.size();i++){
            if(a==0 and b==0)
            {
                a=1,b=1;
            }
             int t=max(nums[i]*a,max(nums[i],b*nums[i]));
             b=min(nums[i]*b,min(nums[i],nums[i]*a));

           a=t;


            ans=max(ans,a);
        }
        return ans;
    }
};