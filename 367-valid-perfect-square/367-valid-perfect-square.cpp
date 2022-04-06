class Solution {
public:
    bool isPerfectSquare(int n) {
        int start = 0, end = n/2;
        
        if(n == 1) return true;
        
        while(start <= end){
            long mid = start + (end - start) / 2;
            if(mid * mid == n)
                return true;
            else if(mid * mid > n)
                end = (int)mid-1;
            else
                start = (int)mid+1;
        }
        return false;
    }
};