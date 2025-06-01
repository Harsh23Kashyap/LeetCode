class Solution {
public:
long long C2(long long x){
            return (x >= 2) ? (x * (x - 1) / 2) : 0;
        };

    long long distributeCandies(int n, int limit) {
        
        long long N = n, L = limit;
        // Total unconstrained = C(n+2, 2)
        long long total = (N + 2) * (N + 1) / 2;

        long long x1 = N - L + 1; // for one coord > limit
        long long t1 = C2(x1);

        long long x2 = N - 2 * L; // for two coord > limit
        long long t2 = C2(x2);

        long long x3 = N - 3 * L - 1;// for 3 coords > limit
        long long t3 = C2(x3);

        return total - 3 * t1 + 3 * t2 - t3;
    }
};