class Solution {
public:
 int mod=1e9+7;
 // We use rolling hash (Rabin–Karp) to find the longest palindromic prefix.
// As we iterate, we maintain a forward hash and a reverse hash.
// Whenever both hashes match, the substring [0..i] is a palindrome.
// We track the last such index (longest palindromic prefix).
// Then we take the remaining suffix, reverse it, and prepend it to the string
// to form the shortest palindrome.
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