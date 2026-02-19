class Solution {
public:
    int countBinarySubstrings(string s) {
        int pg=0,cg=1;
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cg++;
            }
            else{
                ans+=min(pg,cg);
                pg=cg;
                cg=1;
            }
        }
        ans+=min(pg,cg);
        return ans;
    }
};