class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> u;
        int sum=0;
        u[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(u.find(sum-k)!=u.end())
                count+=u[sum-k];
            
            u[sum]++;
        }
        return count;
        
    }
};