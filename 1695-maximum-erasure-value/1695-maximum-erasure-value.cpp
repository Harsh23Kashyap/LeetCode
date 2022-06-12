class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int,int> u;
        vector<int> prefix(nums.size()+1,0);
        prefix[1]=nums[0];
        for(int i=1;i<nums.size();i++)
             prefix[i+1]=prefix[i]+nums[i];
        // for(int i=0;i<nums.size()+1;i++)
        //      cout<<prefix[i]<<" ";
        // cout<<endl;
        
        int maxs=0;
        int lower=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(u.find(nums[i])==u.end())
            {
                u[nums[i]]=i;
                maxs=max(maxs,prefix[i+1]-prefix[lower+1]);
            }
            else
            {
                lower=max(lower,u[nums[i]]);
                u[nums[i]]=i;
                maxs=max(maxs,prefix[i+1]-prefix[lower+1]);
            }
            //cout<<maxs<<" "<<lower<<endl;
        }
        return maxs;
        
    }
};