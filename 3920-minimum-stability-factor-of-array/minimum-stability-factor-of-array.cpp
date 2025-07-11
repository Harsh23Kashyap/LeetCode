class Solution {
public:    

    struct GcdSparse {
        int hcf(int a, int b) const {
            while (b) {
                int t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
        int n, maxK;
        vector<vector<int>> st;

        GcdSparse(const vector<int>& a, const Solution& sol) {
            n = a.size();
           
            maxK = (int)floor(log2(n));
            st.resize(maxK + 1, vector<int>(n));
            st[0] = a; 

            // 3) build levels 1..maxK
            for (int k = 1; k <= maxK; k++) {
                int fs=pow(2,k);
                int half =fs/2;
                for (int i = 0; i + fs <= n; i++) 
                {
                    st[k][i] = hcf(
                        st[k-1][i],
                        st[k-1][i + half]
                    );
                }
            }
        }

        int query(int L, int R)  {
            int len = R - L + 1;
            int k   = (int)floor(log2(len));
            int half = pow(2,k);
            return hcf(
                st[k][L],
                st[k][R - half + 1]
            );
        }
    };

    // Greedy check: can we ensure no stable subarray > L remains
    bool canReduce(GcdSparse& st, int n, int L, int maxC)  {
        int used = 0, lastMod = -1;
        for (int i = 0; i + L < n; ++i) {
            int j = i + L;
            if (st.query(i, j) >= 2 && lastMod < i) {
                lastMod = j;            
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
