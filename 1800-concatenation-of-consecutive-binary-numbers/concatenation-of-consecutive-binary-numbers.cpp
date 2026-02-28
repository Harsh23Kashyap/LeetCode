class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        const int MOD = 1e9 + 7;
        int bits = 0;

        for (int i = 1; i <= n; i++) {
 
            if ((i & (i - 1)) == 0) {
                bits++;
            }

            ans = ((ans << bits) + i) % MOD;
        }

        return (int)ans;
    }
};