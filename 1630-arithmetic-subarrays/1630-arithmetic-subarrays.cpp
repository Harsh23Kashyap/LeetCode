class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            //vector<int> v = {nums.begin() + l[i], nums.end() + r[i]+1};
            vector<int> v;
            for(int j=l[i];j<=r[i];j++)
                v.push_back(nums[j]);
            sort(v.begin(),v.end());
            bool res=true;
            for(int i=1;i<v.size()-1;i++)
            {
                if(v[i]-v[i-1]!=v[i+1]-v[i])
                {
                    res=false;
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};