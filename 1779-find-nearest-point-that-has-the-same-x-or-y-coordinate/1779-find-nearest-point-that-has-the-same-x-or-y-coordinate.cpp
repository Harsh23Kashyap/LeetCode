class Solution {
public:
    int dist(int x, int y, vector<int>& p)
    {
        return abs(x-p[0])+abs(y-p[1]);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int manhattan=INT_MAX;
        int ind=-1;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]==x or points[i][1]==y)
            {
                if(dist(x,y,points[i])<manhattan)
                {
                    manhattan=dist(x,y,points[i]);
                    ind=i;
                }
            }
        }
        return ind;
        
    }
};