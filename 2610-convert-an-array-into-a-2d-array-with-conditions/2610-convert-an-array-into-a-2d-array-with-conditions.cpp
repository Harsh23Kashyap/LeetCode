class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> u;
        for(auto it:nums)
            u[it]++;
        vector<vector<int>> ans;
        bool cond=true;
        while(cond)
        {
            vector<int> temp;
            bool stil=false;
            for(auto it:u)
            {
                if(it.second>0)
                {
                    temp.push_back(it.first);
                    u[it.first]--;
                    if(it.second>0)
                    stil=true;
                }
                
            }
            if(temp.size()>0)
            ans.push_back(temp);
                cond=stil;
        }
        return ans;
    }
};