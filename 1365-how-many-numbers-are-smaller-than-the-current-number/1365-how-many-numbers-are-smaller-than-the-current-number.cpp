class Solution {
public:
    int getIndex(map<int,int>& temp, int el)
    {
        int ind=0;
        for (auto u:temp)
        {
            if(u.first==el)
                return ind;
            ind+=u.second;
        }
        return -1;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        
        map<int,int> m;
        vector<int> ind;
        for (auto i:nums)
        {
            m[i]++;
        }
        for(auto i:nums)
        {
            ind.push_back(getIndex(m,i));
        }
        return ind;
    }
};