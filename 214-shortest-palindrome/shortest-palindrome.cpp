class Solution {
public:
 bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        if(s.size()==0)
        return "";
        long long base=31,power=1,lhash=0,rhash=0, mod=1e9+7;

        int bestans=0;
        for(int i=0;i<s.size();i++){
            lhash=(lhash*base + (s[i]-'a'+1))%mod;
            rhash=((s[i]-'a'+1)*power+rhash)%mod;
            power=(power*base)%mod;
            // if(lhash==rhash and isPalindrome(s,0,i))
            if(lhash==rhash )
                bestans=i;
        }

        string curr=s.substr(bestans+1);
        reverse(curr.begin(),curr.end());
        return curr+s;


    }
};