class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        unordered_map<int,set<int>> u;
        for(int i=0;i<points.size();i++)
        {
            u[points[i][0]].insert(points[i][1]);
        }
        int store=INT_MAX;
        for(int i=0;i<points.size();i++)
        {
            int Ax=points[i][0];
            int Ay=points[i][1];
            for(int j=i+1;j<points.size();j++)
            {
                int Bx=points[j][0];
                int By=points[j][1];
                if(Ax!=Bx and Ay!=By)
                {
                    int Cx=Bx;
                    int Cy=Ay;
                    int Dx=Ax;
                    int Dy=By;
                    if(u[Cx].find(Cy)!=u[Cx].end() and u[Dx].find(Dy)!=u[Dx].end())
                    {
                        store=min(store,abs(Ax-Bx)*abs(Ay-By));
                    }
                }
                
            }
        }
        if(store==INT_MAX) return 0;
        return store;
    }
};