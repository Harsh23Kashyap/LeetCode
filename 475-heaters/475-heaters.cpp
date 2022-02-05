class Solution {
public:
    bool canCover(vector<int>& houses, vector<int>& heaters,int radius) 
    {
        int i=0,j=0;
        while(i<houses.size() and j<heaters.size())
        {
            if(houses[i]>=heaters[j]-radius and houses[i]<=heaters[j]+radius)
                i++;
            else
                j++;
        }
        if(i!=houses.size())
        return false;
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low=0;
        int high=max(houses[houses.size()-1],heaters[heaters.size()-1]);
        int best=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<mid<<endl;;
            if(canCover(houses,heaters,mid))
             {
                best=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return best;
        
    }
};