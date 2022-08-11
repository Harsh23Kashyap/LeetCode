class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        nums.push_back(INT_MIN);
        int sum=0,maxi=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            //cout<<nums[i]<<endl;
            if(sum==0)
            sum+=nums[i];
            if(nums[i]<nums[i+1])
                sum+=nums[i+1];
            else
            {
                maxi=max(maxi,sum);
                sum=0;
                
            }
        }
        return maxi;
        
    }
};