class Solution {
public:
    void recursion(vector<vector<int>>& res,vector<int> v,vector<int>& nums, int curr)
    {
        if(curr==nums.size())
        {
            res.push_back(v);
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<"Hehe"<<endl;
            return;
        }
        //including curr index
        v.push_back(nums[curr]);
        recursion(res,v,nums,curr+1);
        //excluding curr index;
        v.pop_back();
        int ind=curr+1;
        while(ind<nums.size() and curr<nums.size() and nums[ind]==nums[curr])
            ind++;
        recursion(res,v,nums,ind);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> v;
        recursion(res,v,nums,0);
        
        return res;
    }
};