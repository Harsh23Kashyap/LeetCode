class Solution {
public:
    int convertTime(string current, string correct) 
    {
        int time1=((current[0]-'0')*10+(current[1]-'0'))*60+((current[3]-'0')*10+(current[4]-'0'));
        int time2=((correct[0]-'0')*10+(correct[1]-'0'))*60+((correct[3]-'0')*10+(correct[4]-'0'));
        
        cout<<time1<<" "<<time2<<endl;
        
        
        int sixty=(time2-time1)/60;
        time1+=60*sixty;
         int fifteen=(time2-time1)/15;
        time1+=15*fifteen;
         int five=(time2-time1)/5;
        time1+=5*five;
         int one=(time2-time1)/1;
        time1+=1*one;
        
        return sixty+fifteen+five+one;
            
        
    }
};