class Solution {
public:
    bool canConstruct(string rN, string m) 
    {
        if(rN.length()>m.length()) return false;
        unordered_map<char,int> maprn;
        unordered_map<char,int> mapm;
        for(int i=0;i<rN.length();i++)
            maprn[rN[i]]++;
        for(int i=0;i<m.length();i++)
            mapm[m[i]]++;
        
        for(auto i:maprn)
        {
            if(mapm.find(i.first)==mapm.end())
                return false;
            else if (i.second>mapm[i.first])
                return false;
        }
        return true;
    }
};