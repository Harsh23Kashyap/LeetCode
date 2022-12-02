class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++,b[t[i]-'a']++;
        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            c+=(b[i]-a[i]>0)?(b[i]-a[i]):0;
        }
        return c;
        
    }
};