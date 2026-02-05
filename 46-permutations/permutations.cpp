class Solution {
public:
void pass(int i, vector<int>& nums,  vector<int>& ceh, vector<vector<int>>& ans){
    if(i==nums.size()){
        ans.push_back(ceh);
    }

    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        ceh.push_back(nums[i]);
        pass(i+1,nums,ceh,ans);
        ceh.pop_back();
         swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
vector<int> check;
        pass(0,nums,check,ans);
        return ans;
    }
};