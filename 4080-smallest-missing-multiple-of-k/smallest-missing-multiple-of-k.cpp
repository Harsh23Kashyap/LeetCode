class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> u(nums.begin(),nums.end());
        int i=1;
        while(u.find(k*i)!=u.end())
        i++;
        return k*i;
    }
};