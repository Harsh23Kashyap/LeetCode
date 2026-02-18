class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int onesEven = 0, onesOdd = 0, totalOnes = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                totalOnes++;
                if (i % 2 == 0)
                    onesEven++;
                else
                    onesOdd++;
            }
        }

        int totalZeros = n - totalOnes;

        if (abs(totalOnes - totalZeros) > 1)
            return -1;

        if (totalOnes == totalZeros)
            return min(onesEven, onesOdd);
        else if (totalOnes > totalZeros)
            return onesOdd;   // must start with '1'
        else
            return onesEven;  // must start with '0'
    }
};
