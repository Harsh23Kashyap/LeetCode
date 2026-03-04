class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // max heap: (distance, index)
        priority_queue<pair<long long, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            long long dist = x*x + y*y;   // no sqrt

            pq.push({dist, i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
