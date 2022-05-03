class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.second<=b.second;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        vector<pair<int,int>> v;
        for(int i=0;i<profit.size();i++)
        {
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end(),cmp);
        
        for(int i=1;i<v.size();i++)
        {
            v[i].first=max(v[i-1].first,v[i].first);
        }
        sort(worker.begin(),worker.end());
        int sum=0;
        for(int i=0;i<worker.size();i++)
        {
            int best=0;
            int low=0;
            int hi=v.size()-1;
            int maxi=-1;
            while(low<=hi)
            {
                int mid=(low+hi)/2;
                if(v[mid].second<=worker[i])
                {
                    maxi=mid;
                    low=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
            if(maxi!=-1)
            sum+=v[maxi].first;

        }
        return sum;
        
    }
};