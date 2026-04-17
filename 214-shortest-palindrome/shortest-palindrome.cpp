class Solution {
public:
 int mod=1e9+7;
    string shortestPalindrome(string s) {
        if(s.size()==0)
        return "";
        long long rhash=0,lhash=0;
         long long base=31;
       
         long long power=1;
         long long last=0; 
        string ans="";
        for(int i=0;i<s.size();i++){
            lhash=(lhash*base+ (s[i]-'a'+1))%mod;
            rhash=(rhash+ power*(s[i]-'a'+1))%mod;
            power = (power * base) % mod;
           
            if(lhash==rhash){
               last=i;
            }
        }
        string rem=s.substr(last+1);
        reverse(rem.begin(),rem.end());
        return rem+s;
    }
};