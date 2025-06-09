class Solution {
public:
    long long numberOfWays(string s) {
        long long ans=0;
        long long sufone=0;
        long long sufzero=0;
        long long prefone=0;
        long long prefzero=0;
        if(s[0]=='0')
            prefzero++;
        else
            prefone++;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                sufzero++;
            }
            else{
                sufone++;
            }
        }

        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0')
            {
                ans+=(1ll*prefone*sufone);
                sufzero--;
                prefzero++;
            }
            else if(s[i]=='1')
            {
                ans+=(1ll*prefzero*sufzero);
                sufone--;
                prefone++;
            }
        }
        return ans;
    }
};