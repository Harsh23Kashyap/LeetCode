class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> u;
        for(auto it:nums){
            if(u.find(it)==u.end())
            u.insert(it);
            else
            return it;
        }
        return -1;
    }
};