class Solution {
public:
    int fib(int n) 
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int left=0,right=1,res=left+right;
        for(int i=3;i<=n;i++)
        {
            int dup=right;
            left=right;
            right=res;
            res=dup+right;
        }
        return res;
    }
};