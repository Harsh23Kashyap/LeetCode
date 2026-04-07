class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l=0,r=0;
        vector<int> freq(26,0);
        int bfreq=0; 
        int best=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            bfreq=max(bfreq,freq[s[r]-'A']);

            while(l<=r and (r-l+1)-bfreq>k)
            {
                freq[s[l]-'A']--; 
                l++;
                bfreq=*max_element(freq.begin(),freq.end());
            }
            r++;
            best=max(best,r-l);

        }
        return best;
    }
};