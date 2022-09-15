class Solution {
public:
    bool static comp(int &i, int &j)
    {
       return abs(i)<abs(j);
    }
    bool canReorderDoubled(vector<int>& changed) 
    {
        unordered_map<int,int> mp;
        for(auto it: changed)
            mp[it]++;
        sort(changed.begin(), changed.end(), comp); 
        for(auto it: changed)
        {
            if(mp[it] > 0)
            {
                mp[it]--;
                if(mp[it * 2] > 0)
                    mp[it * 2]--;
                else{
                    return false;
                }
            }

        }
    
        return true;
    }
};