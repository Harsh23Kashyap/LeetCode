class Solution {
public:
    int minimumOneBitOperations(int n) {
        int k=0;
        if(n==0)
            return 0;
        
        while(pow(2,k)<=n)
            k++;
        k--;
        
        return pow(2,k+1)-1-minimumOneBitOperations(((int)(pow(2,k)))^n);
    }
};