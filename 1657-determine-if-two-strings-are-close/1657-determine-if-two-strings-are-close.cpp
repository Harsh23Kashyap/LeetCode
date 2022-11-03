class Solution {
public:
    bool closeStrings(string s1, string s2) 
    {
        if(s1.size()!=s2.size())
            return false;
        vector<int> a(26,0);
        vector<int> b(26,0);
        unordered_set<char> sa,sb;
        for(int i=0;i<s1.size();i++)
        {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
            sa.insert(s1[i]);
            sb.insert(s2[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b and sa==sb;
        
    }
};