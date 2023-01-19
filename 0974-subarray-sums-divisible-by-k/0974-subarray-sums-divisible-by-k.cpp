class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int> u;
        u[0]=1;
        int sum=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            
            if(rem<0)
                rem+=k;
            
            if(u.find(rem)!=u.end())
                c+=u[rem];
            
            u[rem]++;
        }
        return c;
        
        
    }
};