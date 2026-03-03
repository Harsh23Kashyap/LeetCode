class Solution {
public:
    string invertBit(string s){
        string ans="";
        for(auto it:s)
            ans+=(it=='1')?"0":"1";
        return ans;
    }
    string reverse(string a){
        int i=0;
        while(i<a.size()/2){
            swap(a[i],a[a.size()-i-1]);
            i++;
        }
        
        return a;
    }
    char si(string s, int n, int k){
        if(n==0)
            return s[k-1];
        string res=s+"1"+reverse(invertBit(s));
        // cout<<res<<endl;
        return si(res,n-1,k);
        
    }
    char findKthBit(int n, int k) {
        return si("0",n-1,k);
    }
};