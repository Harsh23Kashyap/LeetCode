class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total==x)
            return nums.size();
        int k=total-x;
        map<int,int> m;
        m[0]=-1;
        int sum=0;
        int longest=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
            {
                
                longest=max(longest,i-m[sum-k]);
                //cout<<nums[i]<<".      "<<i-m[sum-k]<<endl;
            }
            if(m.find(sum)==m.end())
            {
                m[sum]=i;
            }
           
        }
        if(longest==0)
            return -1;
        return nums.size()-longest;
    }
};