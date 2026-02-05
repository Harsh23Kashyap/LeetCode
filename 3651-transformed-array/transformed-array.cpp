class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        if(nums.size()==1)
        return nums;
        vector<int> ans=nums;
        for(int i=0;i<nums.size();i++){
            cout<<i<<endl;
            if(nums[i]>0){
                int tomoveleft=(i+nums[i])%nums.size();
                ans[i]=nums[tomoveleft];
            }
            else if(nums[i]<0){
                int tomoveleft=(i+nums[i]);
                if(tomoveleft>=0)
                ans[i]=nums[tomoveleft];
                else{
                    int rem=(-1*tomoveleft)%nums.size();
                    if(rem==0)
                    ans[i]=nums.front();
                    else
                    ans[i]=nums[nums.size()-rem];
                }
            }

        }
        return ans;

    }
};