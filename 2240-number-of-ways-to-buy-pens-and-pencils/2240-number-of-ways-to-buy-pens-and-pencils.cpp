class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        if(total<cost1)
            return (total/cost2)+1;
        else if(total<cost2)
            return (total/cost1)+1;
        else 
        {
            //cout<<"Rins"<<endl;
            long long count=0;
            int x=max(cost1,cost2);
            int y=min(cost1,cost2);
            for(long long i=0;i<=total;i+=x)
            {
                count++;
                count+=((total-i)/y);
                
            }
             return count;
        }
       return 1;
        
        
    }
};
