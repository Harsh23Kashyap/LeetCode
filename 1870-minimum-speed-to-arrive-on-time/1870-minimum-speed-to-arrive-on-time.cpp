class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int speed)
    {
        double total=0.0;
        for(int i=0;i<dist.size()-1;i++)
        {
            total+=(ceil(dist[i]*1.0/(speed*1.0)));
            if(total>hour)
            {
                //cout<<"Total - "<<total<<endl;
                return false;
            }
        }
        total+=dist[dist.size()-1]*1.0/(speed*1.0);
        if(total>hour)
            {
                //cout<<"Total - "<<total<<endl;
                return false;
            }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        // if(dist.size()>hour+1)
        //     return -1;
        
        int low=1;
        int high=1e9;
        int best=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            //cout<<mid<<endl;
            if(isPossible(dist,hour,mid))
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