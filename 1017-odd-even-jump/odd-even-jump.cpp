class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_higher(n, -1), next_lower(n, -1);

        // Helper lambda to build next jump indices
        auto makeNext = [&](vector<int>& next, vector<pair<int, int>> v) {
            sort(v.begin(), v.end());  // sort by value then index
            stack<int> st;
            for (auto [val, idx] : v) {
                while (!st.empty() && st.top() < idx) {
                    next[st.top()] = idx;
                    st.pop();
                }
                st.push(idx);
            }
        };

        vector<pair<int, int>> up, down;
        for (int i = 0; i < n; ++i) {
            up.emplace_back(arr[i], i);
            down.emplace_back(-arr[i], i);  // reverse for decreasing
        }

        makeNext(next_higher, up);
        makeNext(next_lower, down);

        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            if (next_higher[i] != -1)
                odd[i] = even[next_higher[i]];
            if (next_lower[i] != -1)
                even[i] = odd[next_lower[i]];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (odd[i])
                ans++;

        return ans;
    }
};
