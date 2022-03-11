class Solution {
    unordered_map<int,vector<int>> u;
public:
    
    Solution(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
            u[nums[i]].push_back(i);
    }
    
    int pick(int target) 
    {
        vector<int> res=u[target];
        int ind=rand()%res.size();
        return res[ind];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */