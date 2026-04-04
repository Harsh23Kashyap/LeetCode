class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
        return 0;
        unordered_set<int> visBus;
        unordered_set<int> visStops;

        unordered_map<int,vector<int>> bm;

        // cout << "Building stop -> buses map\n";
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                bm[routes[i][j]].push_back(i);
                // cout << "Stop " << routes[i][j] << " has bus " << i << "\n";
            }
        }

        queue<int> q;

        // cout << "\nInitializing BFS from source: " << source << "\n";
        for(int i:bm[source])
        {
            visBus.insert(i);
            visStops.insert(source);
            q.push(i);
            // cout << "Initial bus added: " << i << "\n";
        }

        int c=1;

        while(!q.empty()){
            int sz=q.size();
            // cout << "\n--- LEVEL " << c << " ---\n";
            // cout << "Queue size: " << sz << "\n";

            while(sz--){
                auto it=q.front();
                q.pop();

                // cout << "\nProcessing Bus: " << it << "\n";

                for(auto stops:routes[it]){
                    // cout << "  Visiting stop: " << stops << "\n";

                    if(stops==target){
                        // cout << "🎯 Found target at stop " << stops << "\n";
                        return c;
                    }

                    if(visStops.find(stops)==visStops.end()){
                        // cout << "  New stop discovered: " << stops << "\n";

                        visStops.insert(stops);

                        for(auto allbus:bm[stops]){
                            // cout << "    Checking bus " << allbus << " at stop " << stops << "\n";

                            if(visBus.find(allbus)==visBus.end()){
                                // cout << "    ➕ Adding new bus: " << allbus << " to queue\n";

                                q.push(allbus);
                                visBus.insert(allbus);
                            } else {
                                // cout << "    ❌ Bus already visited: " << allbus << "\n";
                            }
                        }
                    } else {
                        // cout << "  ❌ Stop already visited: " << stops << "\n";
                    }
                }
            }
            c++;
        }

        // cout << "\nNo route found\n";
        return -1;  
    }
};