class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        //vector<int> v;
        double sum=0,m=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        m=sum;
        for(int i=k;i<nums.size();i++)
        {
            sum=sum+nums[i]-nums[i-k];
            m=max(sum,m);
        }
        return m/k;
        
    }
};