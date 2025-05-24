class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        unordered_set<int> taken(passengers.begin(), passengers.end());
        
        int j = 0; // passenger index
        int lastBusTime = 0, lastBoarded = 0;
        
        for (int i = 0; i < buses.size(); i++) {
            int currBus = buses[i];
            int cap = 0;
            
            while (j < passengers.size() && passengers[j] <= currBus && cap < capacity) {
                lastBoarded = passengers[j];
                j++;
                cap++;
            }

            // If it's the last bus, handle answer logic after loop
            if (i == buses.size() - 1) {
                if (cap < capacity) {
                    // Try latest time ≤ bus that isn't taken
                    for (int t = currBus; t >= 0; t--) {
                        if (!taken.count(t))
                            return t;
                    }
                } else {
                    // Bus full, try just before lastBoarded
                    for (int t = lastBoarded - 1; t >= 0; t--) {
                        if (!taken.count(t))
                            return t;
                    }
                }
            }
        }

        return -1; // Should never reach here per problem constraints
    }
};
