class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) 
    {
        vector<pair<int,int>> nu;
        for(int i=0;i<capital.size();i++)
            nu.push_back({capital[i],profit[i]});
        
        sort(nu.begin(),nu.end());
        priority_queue<int> pq;
        
        int c=w;
        int i=0;
        while(k--)
        {
            for(;i<nu.size() and nu[i].first<=c;i++)
                pq.push(nu[i].second);
            
            if(pq.empty())
                break;
            
            c+=pq.top();
            pq.pop();
            
            
        }
        return c;
        
    }
};