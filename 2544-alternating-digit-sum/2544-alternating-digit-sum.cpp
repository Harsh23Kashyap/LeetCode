class Solution {
public:
    int alternateDigitSum(int n) {
        int rev=0;
        while(n>0)
        {
            rev=rev*10+(n%10);
            n/=10;
        }
        int sum=0,sign=1;;
        
        while(rev>0)
        {
            sum+=(sign*(rev%10));
            sign*=-1;
            rev/=10;
        }
        return sum;
    }
};