class Solution {
public:
    void pass(vector<vector<int>> &ans, vector<int> &curr, vector<int>& nums, int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }

       //take iy
       curr.push_back(nums[i]);
       pass(ans,curr,nums,i+1);
       //leave it
       curr.pop_back();
       while(i+1<nums.size() and nums[i]==nums[i+1])
       i++;
    pass(ans,curr,nums,i+1);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        pass(ans,curr,nums,0);
        return ans;
    }
};