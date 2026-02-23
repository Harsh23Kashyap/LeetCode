class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> u;
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=s[i];
            if(i>=k-1){
                // cout<<ans<<endl;
                u.insert(ans);
                ans=ans.substr(1);
            }
        }
        // cout<<u.size()<<endl;
        // cout<<(1<<k)<<endl;
        return u.size()==(1<<k);
    }
};