class Solution {
public:
    void p(vector<int>& nums,int i,set<vector<int>>& ans)
    {
        //cout<<i<<endl;
        if(i==nums.size())
        {
            ans.insert(nums);
            return;
        }
        //Same index
        p(nums,i+1,ans);
        //swap(nums[i],nums[j]);
        for(int j=i+1;j<nums.size();j++)
        {
            //cout<<j<<endl;
           if(nums[j]==nums[i]) 
               continue;
            swap(nums[i],nums[j]);
            p(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        p(nums,0,ans);
        vector<vector<int>> v;
        for(auto i:ans)
            v.push_back(i);
        return v;
    }
};