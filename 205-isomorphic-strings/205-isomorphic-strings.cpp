class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> u;
        for(char c:s)
            u[c]='\0';
        
        for(int i=0;i<t.length();i++)
        {
            char curr=s[i];
            if(u[curr]=='\0')
                u[curr]=t[i];
            if(u[curr]!=t[i])
                return false;
        }
        unordered_map<char,char> u2;
        for(char c:t)
            u2[c]='\0';
        
        for(int i=0;i<s.length();i++)
        {
            char curr=t[i];
            if(u2[curr]=='\0')
                u2[curr]=s[i];
            if(u2[curr]!=s[i])
                return false;
        }
        return true;
        
        
        
    }
};