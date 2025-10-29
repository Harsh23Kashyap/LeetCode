class Solution {
public:
    int smallestNumber(int n) {
        int bits=log(n)/log(2);
         return pow(2,bits+1)-1;
    }
};