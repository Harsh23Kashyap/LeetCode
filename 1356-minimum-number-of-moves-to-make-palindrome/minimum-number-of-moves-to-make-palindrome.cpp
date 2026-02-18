class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        int moves = 0;

        while (l < r) {
            int k = r;

            // Find matching char for s[l] from right side
            while (k > l && s[k] != s[l])
                k--;

            if (k == l) {
                // This is the middle character
                swap(s[l], s[l + 1]);
                moves++;
            } else {
                // Bring s[k] to position r
                while (k < r) {
                    swap(s[k], s[k + 1]);
                    moves++;
                    k++;
                }
                l++;
                r--;
            }
        }

        return moves;
    }
};
