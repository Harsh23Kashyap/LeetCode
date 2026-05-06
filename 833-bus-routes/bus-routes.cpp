class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBus;
 
        for(int i = 0; i < routes.size(); i++) {
            for(int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        queue<int> q;

        unordered_set<int> visBus;
        unordered_set<int> visStops;
 
        for(int bus : stopToBus[source]) {
            q.push(bus);
            visBus.insert(bus);
        }

        visStops.insert(source);

        int busesTaken = 1;

        while(!q.empty()) 
        {

            int sz = q.size();
            while(sz--) {
                

                int bus = q.front();
                q.pop();

                // explore all stops of this bus
                for(int stop : routes[bus]) {

                    // reached target
                    if(stop == target)
                        return busesTaken;

                    // already processed this stop
                    if(visStops.count(stop))
                        continue;

                    visStops.insert(stop);

                    // from this stop, what buses can we take?
                    for(int nextBus : stopToBus[stop]) {

                        if(visBus.count(nextBus))
                            continue;

                        visBus.insert(nextBus);
                        q.push(nextBus);
                    }
                }
            }

            busesTaken++;
        }

        return -1;
    }
};