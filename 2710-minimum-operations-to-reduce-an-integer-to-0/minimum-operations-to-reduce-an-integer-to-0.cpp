class Solution {
public:
unordered_map<int,int> u;
    int minOperations(int n) {
        if(n==0)
        return 0;
        if(u.count(n))
        return u[n];
        int msb = 31 - __builtin_clz(n);
        if((n&(n-1))==0)
            return u[n] = 1;
        int nh=1<<(msb+1);
        int nl=1<<(msb);


        return u[n]=min(minOperations(n-nl),minOperations(nh-n))+1;
    }
};