class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v {};
        unordered_map<int,int> u1;
        unordered_map<int,int> u2;
        for(int i=0;i<nums1.size();i++)
        {
            u1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            u2[nums2[i]]++;
        }
        for(auto it:u1)
        {
            if(u2.find(it.first)!=u2.end())
                for(int i=0;i< min(u1[it.first],u2[it.first]);i++)
                    v.push_back(it.first);
        }
        return v;
    }
};