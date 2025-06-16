class Solution {
public:
bool isPrime(int a){
    if(a==1)
    return false;
    for(int j=2;j<=sqrt(a);j++){
        if(a%j==0)
        return false;
    }
    return true;
}
    int nonSpecialCount(int l, int r) {
        int min=sqrt(l),max=sqrt(r);
        cout<<min<<" "<<max<<endl;
        if(min*min<l){
            min++;
        }
        int c=0;
        for(int k=min;k<=max;k++){
            if(isPrime(k))
            c++;
        }
        // cout<<c<<endl;
        return r-l+1-c;

    }
};