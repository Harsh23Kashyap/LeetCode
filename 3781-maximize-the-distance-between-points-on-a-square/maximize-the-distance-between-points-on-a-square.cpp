class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long L = 4LL * side;

        vector<long long> pos;
        for (auto &p : points) {
            long long x = p[0], y = p[1];

            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(3LL * side - x);
            else pos.push_back(4LL * side - y);
        }

        sort(pos.begin(), pos.end());

        // duplicate
        vector<long long> ext = pos;
        for (auto x : pos) ext.push_back(x + L);

        int m = ext.size();

        auto can = [&](long long D) {
            vector<int> nxt(m);

            // build next jump using binary search
            for (int i = 0; i < m; i++) {
                long long target = ext[i] + D;
                nxt[i] = lower_bound(ext.begin(), ext.end(), target) - ext.begin();
            }

            // try each start
            for (int i = 0; i < n; i++) {
                int count = 1;
                int cur = i;

                for (int step = 1; step < k; step++) {
                    cur = nxt[cur];
                    if (cur >= i + n) break;
                    count++;
                }

                if (count == k) {
                    long long first = ext[i];
                    long long last = ext[cur];

                    if (L - (last - first) >= D)
                        return true;
                }
            }

            return false;
        };

        long long low = 0, high = L, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};