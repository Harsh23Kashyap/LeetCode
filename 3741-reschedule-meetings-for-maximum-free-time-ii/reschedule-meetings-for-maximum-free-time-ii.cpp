class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> spaces;
        spaces.push_back(st[0]); // gap before first meeting
        for(int i=1; i<n; i++){
            spaces.push_back(st[i] - et[i-1]);
        }
        spaces.push_back(eventTime - et.back()); // gap after last meeting

        // Pair of (gap_size, index)
        vector<pair<int, int>> sortedSpaces;
        for (int i = 0; i < spaces.size(); i++) {
            sortedSpaces.emplace_back(spaces[i], i);
        }

        // Sort by gap size
        sort(sortedSpaces.begin(), sortedSpaces.end());

        int maxi = *max_element(spaces.begin(), spaces.end());

        for(int i=0; i<n; i++) {
            int sz = et[i] - st[i];
            if (i + 1 >= spaces.size()) continue;

            // Binary search to find first gap >= sz
            auto it = lower_bound(sortedSpaces.begin(), sortedSpaces.end(), make_pair(sz, -1));
            while (it != sortedSpaces.end()) {
                int idx = it->second;
                if (idx != i && idx != i + 1) {
                    // Valid position to shift
                    int totalSizeHere = spaces[i] + spaces[i+1] + sz;
                    maxi = max(maxi, totalSizeHere);
                    break;
                }
                ++it;
            }

            // Also consider just merging the two gaps without shifting
            int totalSizeHere = spaces[i] + spaces[i+1];
            maxi = max(maxi, totalSizeHere);
        }

        return maxi;
    }
};
