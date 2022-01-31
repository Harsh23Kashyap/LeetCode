class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int,long> u;
        for(int i=0;i<time.size();i++)
            u[time[i]%60]++;
        long long count=0;
        for(auto i:u)
        {
            if(i.first==30 || i.first==0)
                count+=(i.second*(i.second-1))/2;
            else
            {
                int n=i.first;
                if(n>30)
                {
                    if(u.find(60-n)!=u.end())
                    {
                        count+=(i.second*u[60-n]);
                    }
                }
            }
        }
        return count;
        
    }
};