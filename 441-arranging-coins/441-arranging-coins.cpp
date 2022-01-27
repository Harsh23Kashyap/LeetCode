class Solution {
public:
    int arrangeCoins(int n) 
    {
        long start=0,end=n,best=0;
        while(start<=end)
        {
            long mid=(start+end)/2;
            long coin=mid*(mid+1)/2;
            if(coin==n)
            {
                best=mid;
                    break;
            }
            if(coin<n)
            {
                best=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return best;
    }
};