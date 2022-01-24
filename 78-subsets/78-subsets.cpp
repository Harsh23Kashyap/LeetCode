class Solution {
public:
    vector<int> pass(vector<int>& nums, int curr)
    {
        vector<int> v;
        int ind=0;
        while(curr>0)
        {
            if(curr&1)
                v.push_back(nums[ind]);
            curr=curr>>1;
            ind++;
        }
        return v;
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> sub;
        sub.push_back({});
        for(int i=1;i<(1<<nums.size());i++)
        {
            sub.push_back(pass(nums,i));
        }
        return sub;
    }
};