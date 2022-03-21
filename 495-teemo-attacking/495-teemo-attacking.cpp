class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int total=0;
        int end=-1;
        for(int i=0;i<timeSeries.size();i++)
        {
            if(timeSeries[i]<=end)
            {
                int curr=timeSeries[i]+duration-1;
                total+=curr-end;
                end=curr;
            }
                
            else
            {
                end=timeSeries[i]+duration-1;
                total+=duration;
            }
            
        }
        return total;
        
    }
};