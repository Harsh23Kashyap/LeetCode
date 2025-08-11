class Solution {
public:
    int m = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % m;
            base = (base * base) % m;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int cp = 1;
        while (n > 0) {
            if (n & 1) {
                power.push_back(cp);
            }
            cp *= 2;
            n >>= 1;
        }

        vector<long long> ps;
        for (int i = 0; i < power.size(); i++) {
            if (i == 0)
                ps.push_back(power[i] % m);
            else
                ps.push_back((ps.back() * power[i]) % m);
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long numerator = ps[r];
            long long denominator = (l == 0 ? 1 : ps[l - 1]);

            // Use modular inverse instead of division
            long long inv = modPow(denominator, m - 2);
            long long res = (numerator * inv) % m;
            ans.push_back((int)res);
        }
        return ans;
    }
};
