class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        if(buckets--==0)
            return 0;
        
        int bb=minutesToTest/minutesToDie +1;
        int res=0;
        while(buckets>0)
        {
            buckets/=bb;
            res++;
        }
        return res;
        
    }
};