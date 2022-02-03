class Solution {
public:
    int mod=1e9+7;
    long power(long a,long n)
    {
        if(n==0)
        return 1;
        long long ans=power(a,n/2);
        if(n % 2 == 0)
            return (ans * ans) % mod;
        else
            return (((a * ans) % mod) * ans) % mod;
    }
    
    int countGoodNumbers(long long n) 
    {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % mod;
    }
};