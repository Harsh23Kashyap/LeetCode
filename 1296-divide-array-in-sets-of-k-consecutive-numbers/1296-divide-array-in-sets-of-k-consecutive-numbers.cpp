class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        if(nums.size()%k!=0)
            return false;
        unordered_map<int,int> am;
        for(int i:nums)
            am[i]++;
        
        for(int i=0;i<nums.size();i++)
        {
            //cout<<nums[i]<<endl;
            if(am[nums[i]]<=0)
                continue;
            else 
            {
                for(int j=nums[i];j<nums[i]+k;j++)
                {
                    //cout<<j<<" ";
                    if(am[j]==0)
                        return false;
                    am[j]--;
                        
                }
            }
            //cout<<endl;
        }
        return true;
        
    }
};