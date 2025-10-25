class Solution {
public:
    int totalMoney(int n) {
        int sum=28;
        int ans=0;
        int st=1;
        while(n>=7){
            ans+=sum;
            n-=7;
            sum+=7;
            st++;
        }
        while(n>0){
            ans+=st++;
            n--;
        }
        return ans;
    }
};