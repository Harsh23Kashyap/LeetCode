class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++)
        {
            u[nums[i]]++;
        }
        int c=0;
        if(k!=0)
        {
            for(auto i:u)
            {
                int f=i.first+k;
                if(u.find(f)!=u.end())
                    c++;
            }
        }
        else
        {
            for(auto i:u)
            {
                if(i.second>1)
                    c++;
            }
        }
        
        return c;
    }
};