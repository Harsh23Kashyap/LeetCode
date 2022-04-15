class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        vector<int> dup;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                continue;
            else
            {
                //cout<<nums[i]<<endl;
                dup.push_back(nums[i]);
            }
        }
        if(dup.size()==0)
            return 0;
        if(nums[nums.size()-1]!=dup[dup.size()-1])
            dup.push_back(nums[nums.size()-1]);
        int c=0;
        for(int i:dup)
            cout<<i<<" ";
        for(int i=1;i<dup.size()-1;i++)
        {
            if(dup[i-1]<dup[i] and dup[i+1]<dup[i])
                c++;
            else  if(dup[i-1]>dup[i] and dup[i+1]>dup[i])
                c++;
        }
        return c;
        
    }
};