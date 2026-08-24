class Solution {
public:
    int sd(int a){
        int sum=0;
        while(a>0){
            sum+=(a%10);
            a/=10;
        }
        return sum;
    }
    int asd(int a){
        long long sum=1;
        while(a>0){
            sum*=(a%10);
            a/=10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        return n%(sd(n)+asd(n))==0;
        
    }
};