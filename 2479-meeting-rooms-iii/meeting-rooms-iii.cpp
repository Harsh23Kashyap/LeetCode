class Solution {
public:
// typedef long long int;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        set<long long> s;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        unordered_map<int,int> u;
        for(int i=0;i<n;i++)
        s.insert(i);
        for(int i=0;i<meetings.size();i++){

           long long start=meetings[i][0],end=meetings[i][1];

           while(!pq.empty() and pq.top().first<=start){
                auto it=pq.top();
                pq.pop();
                s.insert(it.second);
           }

           if(s.size()==0){
                auto it=pq.top();
                pq.pop();
                long long curr=it.first;
                long long duration = end-start;
                long long endtime=curr+duration;
                u[it.second]++;
                pq.push({endtime,it.second});

           }
           else{
              auto k=*s.begin();
              long long endtime=end;
              u[k]++;
              s.erase(k);
              pq.push({endtime,k});

           }


        }

        int val=0;
        int maxi=0;

        for(auto it:u){
            if(it.second>val){
                val=it.second;
                maxi=it.first;
            }
            else if(it.second==val){
                val=it.second;
                maxi=min(maxi,it.first);
            }
        }

        return maxi;
    }
};