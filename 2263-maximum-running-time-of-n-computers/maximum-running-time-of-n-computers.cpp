class Solution {
public:
long long possible(long long  m, vector<int>& batteries, int n){
    long long  rem=0;
    for(auto it:batteries)
        rem+=m<it?m:it;
    return rem>=1ll*n*m;
}
    long long maxRunTime(int n, vector<int>& batteries) {
        long long tp=accumulate(batteries.begin(),batteries.end(),0ll);
        long long l=0,r=tp/n;
        long long ans=0;
        while(l<=r){
            long long m= l+(r-l)/2;

            if(possible(m,batteries,n)){
                cout<<m<<endl;
                ans=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        return ans;
    }
};