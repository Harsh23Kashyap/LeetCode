class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> u;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
            u[nums[i]].push_back(i);

        for(auto it:u){
            auto &v=it.second;
            if(v.size()<3)
            continue;
            
            for(int i=0;i<v.size()-2;i++){
                mini=min(mini, v[i+1]-v[i]+v[i+2]-v[i+1]+v[i+2]-v[i]);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};