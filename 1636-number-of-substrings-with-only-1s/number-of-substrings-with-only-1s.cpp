class Solution {
public:
int m=1e9+7;
long long fact(long long n){
    long long ans=(n*(n+1)/2)%m;
    return ans%m;
}
    int numSub(string s) {
        s=s+'0';
        int c=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c++;
            }
            else
            {
                cout<<i<<" "<<c<<endl;
                ans+=fact(c)%m;
                cout<<fact(c)<<endl;
                c=0;

            }
        }
        return ans;
    }
};