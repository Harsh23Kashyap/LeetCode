class Solution {
public:
    int sum(int n)
    {
        int c=0;
        while(n>0)
        {
            c+=(n%10);
            n/=10;
        }
        return c;
    }
    int countBalls(int lowLimit, int highLimit) 
    {
        unordered_map<int,int> u;
        int maxi=0;
        for(int i=lowLimit;i<=highLimit;i++)
        {
            int curr=sum(i);
            u[curr]++;
           maxi=max(maxi,u[curr]);
        }
        return maxi;
        
    }
};