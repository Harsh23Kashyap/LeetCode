class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        int m=INT_MIN;
        for(int i=0;i<points.size()-1;i++)
        {
            m=max(abs(points[i][0]-points[i+1][0]),m);
        }
        return m;
    }
};