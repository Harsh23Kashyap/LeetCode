class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> u;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                u[routes[i][j]].push_back(i);
            }
        }

        unordered_set<int> bus;
        unordered_map<int,int> currstops;

        queue<pair<int,int>> q;
        q.push({source,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                if(it.first==target)
                return it.second;
                if(currstops[it.first]<it.second)
                    continue;

                for(auto allbus:u[it.first]){
                    if(bus.count(allbus))
                        continue;
bus.insert(allbus);  
                    for(int stops:routes[allbus]){
                        if(currstops.find(stops)==currstops.end() or it.second+1<currstops[stops]){
                            currstops[stops]=it.second+1;
                            q.push({stops,it.second+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};