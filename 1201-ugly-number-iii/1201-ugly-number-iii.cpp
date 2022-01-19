#define MAX 2*(1e9)
typedef long long ll;
class Solution {
public:
    ll lcm(ll a, ll b)
    {
        return a*b/__gcd(a,b);
    }
    ll count(ll n, ll a, ll b, ll c)
    {
        return (n/a)+(n/b)+(n/c)-(n/lcm(a,b))-(n/lcm(c,b))-(n/lcm(a,c))+(n/lcm(c,lcm(a,b)));
    }
    int nthUglyNumber(ll n, ll a, ll b, ll c) 
    {
        //if(n==1 )
        ll start=0, end= MAX;
        ll res;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(count(mid,a,b,c)>=n)
            {
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
};