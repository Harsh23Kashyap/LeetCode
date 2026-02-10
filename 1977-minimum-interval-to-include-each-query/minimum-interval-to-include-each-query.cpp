class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& v, vector<int>& queries) {
        vector<pair<int,int>> qq;
        for(int i=0;i<queries.size();i++)
            qq.push_back({queries[i],i});
        sort(qq.begin(),qq.end());
        sort(v.begin(),v.end());
        vector<int>  ans(qq.size(),-1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int i=0;
        for(auto jt:qq){
            int it=jt.first;
            while(i<v.size() and v[i][0]<=it){
                pq.push({v[i][1]-v[i][0]+1,v[i][0],v[i][1]});
                i++;
            }
            while(!pq.empty() and pq.top()[2]<it)
            pq.pop();

            if(!pq.empty())
                ans[jt.second]=(pq.top()[0]);
        }
        return ans;

    }
};