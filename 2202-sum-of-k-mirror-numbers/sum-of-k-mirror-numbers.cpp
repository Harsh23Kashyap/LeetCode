class Solution {
public:
    // ✅ Converts a number to base-k and checks if it's a palindrome
    bool isBaseKPalindrome(long long num, int k) {
        long long rev = 0, orig = num;
        while (num > 0) {
            rev = rev * k + (num % k);
            num /= k;
        }
        return rev == orig;
    }

    // ✅ Generates a decimal palindrome from its first half
    long long createPalindrome(int half, bool oddLength) {
        long long pal = half;
        if (oddLength) half /= 10;

        while (half > 0) {
            pal = pal * 10 + (half % 10);
            half /= 10;
        }
        return pal;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // ✅ Generate palindromes of increasing length
        for (int len = 1; count < n; len++) {
            int start = pow(10, (len - 1) / 2);    // half digits
            int end = pow(10, (len + 1) / 2);

            for (int half = start; half < end; half++) {
                long long pal = createPalindrome(half, len % 2 == 1);
                if (isBaseKPalindrome(pal, k)) {
                    sum += pal;
                    count++;
                    if (count == n) return sum;
                }
            }
        }
        return sum;
    }
};
