class Solution {
public:
    bool isPossible(vector<int> position, int m, int magnet)
    {
        int last=position[0];
        m--;
        for(int i=1;i<position.size();i++)
        {
           
            if(position[i]-last>=magnet)
            {
                last=position[i];
                m--;
            }
             if(m<=0)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(),position.end());
        int low=1,high=position[position.size()-1];
        int best=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            //cout<<mid<<endl;
            if(isPossible(position,m,mid))
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