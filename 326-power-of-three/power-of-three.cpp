class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int exp = round(log(n) / log(3));
        return pow(3, exp) == n;
    }
};
