class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector <pair<vector<int>,int>> v;
        vector <int> a;
        for (int i=0;i<mat.size();i++)
        {
            v.push_back(make_pair(mat[i],i));
        }
        sort(v.begin(),v.end());
        for (int i=0;i<k;i++)
        {
            a.push_back(v[i].second);
        }
        return a;
    }
};