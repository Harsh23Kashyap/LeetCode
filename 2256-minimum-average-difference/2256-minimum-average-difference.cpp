class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long> left(n,0);
        left[0]=nums[0];
        vector<long long> right(n,0);
        right[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++)
            left[i]=left[i-1]+nums[i];
        
        for(int i=n-2;i>=0;i--)
            right[i]=right[i+1]+nums[i];
        
        long long ind=0;
        long long val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            long long l=left[i]/(i+1);
            long long r=0;
            if(i!=n-1)
                r=right[i+1]/(n-i-1);
            
            if(abs(l-r)<val)
            {
                val=abs(l-r);
                ind=i;
            }
        }
        return ind;
        
        
    }
};