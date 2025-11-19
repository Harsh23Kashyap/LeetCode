class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> u(nums.begin(),nums.end());

        while(u.find(original)!=u.end())
            original*=2;
        
        return original;
    }
};