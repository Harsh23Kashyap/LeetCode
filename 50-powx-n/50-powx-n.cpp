class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0)
            return 1;
        int a=1;
        if(n<0)
        {
            a=-1;
            n=abs(n);
        }
        double ans=1;
        double aaa=x;
        while(n>0)
        {
            if(n&1)
                ans*=aaa;
            n=n>>1;
            aaa*=aaa;
        }
        
        if(a==1)
            return ans;
        return 1.0/ans;
        
        
    }
};