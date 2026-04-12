class Solution {
public:
    string s;
    int n;
    const long long mod = 1e9 + 7;
    const int base = 31;

string check(int len) {
    unordered_map<long long, vector<int>> mp;

    long long hash = 0, power = 1;

    // first window
    for (int i = 0; i < len; i++) {
        hash = (hash * base + (s[i] - 'a' + 1)) % mod;
        if (i < len - 1)
            power = (power * base) % mod;
    }

    mp[hash].push_back(0);

    for (int i = len; i < n; i++) {
        // remove left char
        hash = (hash - (s[i - len] - 'a' + 1) * power % mod + mod) % mod;

        // add new char
        hash = (hash * base + (s[i] - 'a' + 1)) % mod;

        int start = i - len + 1;

        if (mp.count(hash)) {
            for (int prevStart : mp[hash]) {
                if (s.substr(prevStart, len) == s.substr(start, len)) {
                    return s.substr(start, len); // ✅ verified match
                }
            }
        }

        mp[hash].push_back(start);
    }

    return "";
}
    string longestDupSubstring(string _s) {
        s = _s;
        n = s.size();

        int l = 1, r = n;
        string ans = "";

        while (l <= r) {
            int mid = (l + r) / 2;

            string res = check(mid);

            if (res != "") {
                ans = res;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};