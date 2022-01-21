class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) 
    {
        int sh=(loginTime[0]-'0')*10+(loginTime[1]-'0');
        int sm=(loginTime[3]-'0')*10+(loginTime[4]-'0');
        int eh;
        if(logoutTime.compare(loginTime)<0)
            eh=((logoutTime[0]-'0')*10+(logoutTime[1]-'0'))+24;
        else
            eh=(logoutTime[0]-'0')*10+(logoutTime[1]-'0');
        int em=(logoutTime[3]-'0')*10+(logoutTime[4]-'0');
        int startmin= sh*60+sm;
        int endmin=eh*60+em;
        cout<<" Start "<<sh<<" : "<<sm<<endl;
        cout<<" End "<<eh<<" : "<<em<<endl;
        int count=0;
        for(int i=sh*60;i<(eh+1)*60;i+=15)
        {
            if(i>=startmin && (i+15)<=endmin)
                count++;
        }
        
        return count;
    }
};