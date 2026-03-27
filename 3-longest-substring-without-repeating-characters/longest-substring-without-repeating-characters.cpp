class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxi=0;
        unordered_map<char,int> u;
        while(r<s.size()){
            if(u.find(s[r])!=u.end()){
                if(l<=u[s[r]])
                    l=u[s[r]]+1;
                
            }
            u[s[r]]=r;

            maxi=max(maxi,r-l+1);
            // cout<<s.substr(l,r-l+1)<<endl;
            r++;
        }
        return maxi;
    }
};