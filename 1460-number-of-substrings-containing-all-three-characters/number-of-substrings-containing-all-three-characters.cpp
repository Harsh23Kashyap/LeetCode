class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,c=0;
        vector<int> freq(3,0);

        while(r<s.size()){
            freq[s[r]-'a']++;
            while(l<r and freq[0]>0 and freq[1]>0 and freq[2]>0){
                c+=s.size()-r;
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return c;
    }
};