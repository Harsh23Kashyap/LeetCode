class Solution {
public:
    const long long m = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long odd = (n + 1) / 2;  
        long long even = n / 2;      

        long long res = (modPow(5, odd) * modPow(4, even)) % m;
        return (int)res;
    }

    long long modPow(long long a, long long b) {
        long long result = 1;
        a %= m;

        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b /= 2;
        }

        return result;
    }
};
