class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<pair<int,int>> v;
        for(int i=0;i<points.size();i++)
        {
            int d=pow(points[i][0],2)+pow(points[i][1],2);
            v.push_back(make_pair(d,i));
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(points[v[i].second]);
        }
        return ans;
    }
};