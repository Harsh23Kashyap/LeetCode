class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        
        int i=0,j=1;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int k=0;k<n;k++)
        {
            if(nums[k]>0) 
            {
                ans[i]=nums[k];
                i+=2;
            }
            else 
            {
                ans[j]=nums[k];
                j+=2;
            }
        }
        return ans;
    }
};