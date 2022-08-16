class Solution {
public:
    int countHousePlacements(int n) 
    {
        int m=1e9+7;
        long long first=2,second=3;
        if(n==1)
            return first*first;
        if(n==2)
            return second*second;
        long long ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=(first+second)%m;
            first=second;
            second=ans;
        }
        return (ans*ans)%m;
        
    }
};