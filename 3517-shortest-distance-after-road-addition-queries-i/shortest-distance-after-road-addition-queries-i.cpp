class Solution {
public:
    int totalStop( int n,unordered_map<int, vector<int>> u )
    {
        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<int> v;
            while(!q.empty())
            {
                auto it=q.front();
                int curr=it.first;
                int stop=it.second;
                q.pop();
                for(auto x:u[curr])
                {
                    if(x==n-1)
                        return stop+1;
                    if(v.find(x)==v.end())
                    {
                        v.insert(x);
                        q.push({x,stop+1});
                    }
                }
            }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> u;
        
        for(int i=0;i<n;i++)
            u[i]={i+1};
        
        vector<int> ans;
        for(auto it:queries)
        {
            u[it[0]].push_back(it[1]);
           ans.push_back(totalStop(n,u));
        }
        return ans;
    }
};