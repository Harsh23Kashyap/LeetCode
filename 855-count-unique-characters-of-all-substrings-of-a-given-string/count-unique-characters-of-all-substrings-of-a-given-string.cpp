class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        unordered_map<char, set<int>> mp;

        // store indices
        for (int i = 0; i < n; i++) 
            mp[s[i]].insert(i);
        

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            auto &st = mp[s[i]];

            auto it = st.find(i);

            int prev = -1;
            int next = n;

            // previous occurrence
            if (it != st.begin()) {
auto pit = std::prev(it);
                prev = *pit;
            }

            // next occurrence
            auto nit = std::next(it);
            if (nit != st.end()) {
                next = *nit;
            }

            ans += 1LL * (i - prev) * (next - i);
        }

        return ans;
    }
};
