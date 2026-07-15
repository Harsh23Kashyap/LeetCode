class Solution {
public:
    int gcd(int a, int b){
        if(a%b==0)
            return b;
        
        return gcd(b,a%b);

    }
    int gcdOfOddEvenSums(int n) {
        
        int sumeven=((2*1+(n-1)*2)*n)/2;
        int sumodd=((2*2+(n-1)*2)*n)/2;
        // cout<<sumeven<<" "<<sumodd<<endl;
        return gcd(sumeven,sumodd);
    }
};