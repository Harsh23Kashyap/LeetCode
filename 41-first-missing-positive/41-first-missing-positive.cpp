class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                nums[i]=0;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int val=abs(nums[i]);
            //cout<<i<<" - "<<val<<endl;
            if(val>=1 and val<=nums.size())
            {
                if(nums[val-1]>0)
                    nums[val-1]=-1*(nums[val-1]);
                if(nums[val-1]==0)
                    nums[val-1]=-1*(nums.size()+110);
                    
            }
        }
        
        for(int i=1;i<nums.size()+1;i++)
        {
            //cout<<nums[i-1]<<endl;
            if(nums[i-1]>=0)
                return i;
            
        }
        return nums.size()+1;
        
    }
};