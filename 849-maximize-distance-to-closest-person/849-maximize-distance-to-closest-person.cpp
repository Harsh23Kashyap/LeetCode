class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int n=seats.size();
        int m=INT_MIN;
        vector<int> left(n,0);
        vector<int> right(n,0);
        if(seats[0]==0) 
            left[0]=2*10000;
        if(seats[n-1]==0) 
            right[n-1]=2*10000;
        for(int i=1;i<n;i++)
        {
            if(seats[i]==1)
                left[i]=0;
            else    left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(seats[i]==1)
                right[i]=0;
            else    right[i]=right[i+1]+1;
        }
        for(int i=0;i<n;i++)
            m=max(min(left[i],right[i]),m);
        return m;
            
    }
};