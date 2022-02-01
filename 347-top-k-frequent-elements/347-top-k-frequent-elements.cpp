class Solution {
public:
    static bool sortgreat(const pair<int,int>& p1,const pair<int,int>& p2)
    {
        return p1.first>p2.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m)
        {
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(),sortgreat);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};