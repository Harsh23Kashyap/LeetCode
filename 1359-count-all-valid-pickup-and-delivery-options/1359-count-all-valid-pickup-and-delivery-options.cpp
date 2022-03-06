class Solution {
public:
    int countOrders(int n) 
    {
        int m=1e9+7;
        
        long long total=1;
        
        for(int i=1;i<=n;i++)
        {
            total=((total%m)*(i%m))%m;
            total=((total%m)*((2*i-1)%m))%m;
        }
        return total%m;
    }
};