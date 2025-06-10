class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
if (source == target) return 0;

        unordered_map<int, vector<int>> uu;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                uu[stop].push_back(i);
            }
        }

        unordered_set<int> vss;
        unordered_set<int> visitedBuses;
        queue<int> q;
        q.push(source);
        vss.insert(source);
        int curr=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){

                int currstop=q.front();
                q.pop();

                for(auto nb:uu[currstop]){
                    if(visitedBuses.find(nb)!=visitedBuses.end())
                    continue;

                    visitedBuses.insert(nb);

                    vector<int> stopforbus=routes[nb];
                    for(auto k:stopforbus){
                        if(k==target)
                        return curr;

                        if(vss.find(k)!=vss.end()) continue;
                        vss.insert(k);
                        q.push(k);

                    }
                }
            }
            curr++;

        }

        return -1;
    }
};