class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        hour=hour%12;
        double factor1=6.0;
        double factor2=0.5;
        
        double minutesdeg=minutes*factor1;
        //cout<<minutesdeg<<endl;
        double hoursdeg=(minutes*factor2)+30.0*hour;
        // cout<<hoursdeg<<endl;
        double ans=abs(hoursdeg-minutesdeg);
        return (ans<(360.0-ans))?ans:360.0-ans;
        
        
    }
};