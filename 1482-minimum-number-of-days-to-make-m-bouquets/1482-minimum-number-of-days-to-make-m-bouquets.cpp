class Solution {
public:
    bool isPossible(vector<int> bd,int m,int k,int mid)
    {
        int countDays=0,countBouquets=0;
        for(int i=0;i<bd.size();i++)
        {
            if(bd[i]<=mid)
                countDays++;
            else
                countDays=0;
            if(countDays==k)
            {
                countBouquets++;
                countDays=0;
            }

        }
        return countBouquets>=m;
    }
    int minDays(vector<int>& bd, int m, int k) 
    {
        if(m*k>bd.size()) return -1;
        int start= *min_element(bd.begin(),bd.end());
        int end= *max_element(bd.begin(),bd.end());
        int ans;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(isPossible(bd,m,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
        
    }
};