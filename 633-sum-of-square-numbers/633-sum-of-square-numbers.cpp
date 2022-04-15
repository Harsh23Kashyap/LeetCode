class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        if(c==0 || c==1 || c==2) return true;
        for(long a=0;a<=sqrt(c);a++)
        {
            double b = sqrt(c-pow(a,2));
            if(b==(int)b)
                return true;
        }
        return false;
    }
};