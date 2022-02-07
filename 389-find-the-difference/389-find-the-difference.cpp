class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map <char,int> u1;
        unordered_map <char,int> u2;
        for(int i=0;i<s.length();i++)
            u1[s[i]]++;
        for(int i=0;i<t.length();i++)
            u2[t[i]]++;
        for (auto x : u1)
        {
            if(x.second!=u2[x.first])
                return x.first;
        }
        for (auto x : u2)
        {
            if(u1.find(x.first)==u1.end())
                return x.first;
        }
        return '0';
    }
};