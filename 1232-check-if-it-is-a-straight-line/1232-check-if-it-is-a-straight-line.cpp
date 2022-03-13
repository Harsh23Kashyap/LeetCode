class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        sort(coordinates.begin(),coordinates.end());
        
        int startx=coordinates[0][0];
        int starty=coordinates[0][1];
        int n=coordinates.size();
        if(n==2)return true;
        int endx=coordinates[n-1][0];
        int endy=coordinates[n-1][1];
        
        //cout<<startx<<starty<<endx<<endy<<endl;
        double slope=1.0*(endy-starty)/(endx-startx);
        if(endx-startx==0)
        {
            for(int i=1;i<n-1;i++)
            {
                if(coordinates[i][0]!=startx)
                    return false;

            }
            return true;
        }
        cout<<slope<<endl;
        for(int i=1;i<n-1;i++)
        {
            if(coordinates[i][1]-starty!=slope*(coordinates[i][0]-startx))
                return false;
                
        }
        return true;
        
    }
};