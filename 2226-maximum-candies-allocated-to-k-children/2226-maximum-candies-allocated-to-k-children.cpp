class Solution {
public:
    bool isPossible(vector<int>& candies, long long k, long long mid)
    {
        long long count=0;
        for(int i=0;i<candies.size();i++)
        {
            count+=candies[i]/mid;
            if(count>=k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int best=0;
        int low=1,high=*max_element(candies.begin(),candies.end());
        while(low<=high)
        {
            long long mid=(low+high)/2;
            //cout<<mid<<endl;
            if(isPossible(candies,k,mid))
            {
                best=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return best;
        
    }
};