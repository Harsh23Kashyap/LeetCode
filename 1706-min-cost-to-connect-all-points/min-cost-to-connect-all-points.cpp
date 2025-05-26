class Solution {
public:
typedef pair<int,pair<int,int>> pp;
    struct cmp{

        size_t operator()(const pair<int,int> &a) const{
            size_t f=a.first;
            size_t s=a.second;
            return (f<<16)^s;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<pair<int,int>,vector<pair<pair<int,int>,double>>, cmp> u;
        int n=points.size();
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                u[{points[i][0],points[i][1]}].push_back({{points[j][0],points[j][1]},dist});
                u[{points[j][0],points[j][1]}].push_back({{points[i][0],points[i][1]},dist});
            }
        }

        priority_queue<pp,vector<pp>, greater<pp>> pq;
        int tc=0;
        unordered_set<pair<int,int>,cmp> vis;
        pq.push({0,{points[0][0],points[0][1]}});
        
        while(!pq.empty()){
            auto j=pq.top();
            pq.pop();

            if(vis.find(j.second)!=vis.end())
            continue;
            vis.insert(j.second);

            tc+=j.first;
            for(auto nn:u[j.second]){
                pq.push({nn.second,nn.first});
            }
        }
        return tc;
    }
};