#define ll long long
class Solution {
public:
    ll totalApples(ll n)
    {
        ll tot=0;
        while(n>0)
        {
            ll left=2*((n*n)+((n*(n+1))/2))+n;
            ll top=(2*(n-1)+1)*n+(n-1)*n;
            tot+=2*(left+top);
            n--;
        }
        //cout<<"Apples - "<<tot<<endl;
        return tot;
    }
    long long minimumPerimeter(long long neededApples) 
    {
        ll low=1;
        ll high=100000;
        ll mid=0;
        ll best=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            //cout<<mid<<endl;
            if(totalApples(mid)==neededApples)
                return mid*8;
            if(totalApples(mid)>neededApples)
            {
                best=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return best*8;
        
    }
};