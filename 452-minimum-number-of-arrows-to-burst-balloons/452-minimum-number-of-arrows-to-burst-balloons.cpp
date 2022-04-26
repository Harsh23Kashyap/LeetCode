class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        
        int arrow=1;
        int lower=points[0][0];
        int upper=points[0][1];
        for(int i=0;i<points.size();i++)
        {
            // cout<<"For "<<i+1<<endl;
            // cout<<points[i][0]<<" "<<points[i][1]<<endl;
            // cout<<lower<<" "<<upper<<endl;
            if(points[i][0]>=lower and points[i][0]<=upper)
            {
                lower=max(points[i][0],lower);
                upper=min(points[i][1],upper);
            }
            else
            {
                arrow++;
                lower=points[i][0];
                upper=points[i][1];
            }
        }
        return arrow;
        
    }
};