class Solution {
public:
    // Euclid’s algorithm for GCD
    int hcf(int a, int b) const {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    struct GcdSparse {
        int n, maxK;
        vector<vector<int>> st;
        vector<int> log2;

        GcdSparse(const vector<int>& a, const Solution& sol) {
            n = a.size();
            // 1) precompute log2[i] = floor(log2(i)) for i=1..n
            log2.assign(n + 1, 0);
            for (int i = 2; i <= n; ++i)
                log2[i] = log2[i >> 1] + 1;
            maxK = log2[n];

            // 2) allocate table: (maxK+1) rows × n columns
            st.assign(maxK + 1, vector<int>(n));
            st[0] = a;  // level 0 is the original array

            // 3) build levels 1..maxK
            for (int k = 1; k <= maxK; ++k) {
                int half = 1 << (k - 1);  // 2^(k-1)
                for (int i = 0; i + (half << 1) <= n; ++i) {
                    st[k][i] = sol.hcf(
                        st[k-1][i],
                        st[k-1][i + half]
                    );
                }
            }
        }

        // O(1) query gcd(a[L..R])
        int query(int L, int R, const Solution& sol) const {
            int len = R - L + 1;
            int k   = log2[len];
            int half = 1 << k;
            return sol.hcf(
                st[k][L],
                st[k][R - half + 1]
            );
        }
    };

    // Greedy check: can we ensure no stable subarray > L remains
    bool canReduce(const GcdSparse& st, int n, int L, int maxC) const {
        int used = 0, lastMod = -1;
        for (int i = 0; i + L < n; ++i) {
            int j = i + L;
            if (st.query(i, j, *this) >= 2 && lastMod < i) {
                lastMod = j;            // modify at j
                if (++used > maxC) 
                    return false;
            }
        }
        return true;
    }

    // Main entry: binary-search the minimal stability factor
    int minStable(vector<int>& nums, int maxC) {
        int n = nums.size();
        GcdSparse st(nums, *this);

        int lo = 0, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReduce(st, n, mid, maxC)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
