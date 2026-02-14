class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());

        if(s.find(0)==s.end())
        return s.size();
        return s.size()-1;
    }
};