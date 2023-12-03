class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count=0;
        
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            vector<int> it=points[i];
            int xdiff=abs(it[0]-x);
            int ydiff=abs(it[1]-y);
            x=it[0];
            y=it[1];
            count+=max(xdiff,ydiff);
        }
        return count;
    }
};