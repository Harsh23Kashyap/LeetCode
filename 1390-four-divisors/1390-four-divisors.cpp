class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int cnt=2;
            int sum=1+nums[i];
            for(int j=2;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0 and nums[i]/j==j)
                {
                    sum+=j;
                    cnt++;
                }
                else if(nums[i]%j==0)
                {
                    sum+=(nums[i]/j)+j;
                    cnt+=2;
                }
            }
            
            if(cnt==4)
                ans+=sum;
            
                
        }
        return ans;
        
    }
};