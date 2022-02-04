class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(k>s.length()) return false;
        unordered_map<char,int> u;
        for(int i=0;i<s.length();i++)
            u[s[i]]++;
        
        int c=0;
        for(auto it:u)
            if(it.second%2!=0)c++;
        
        return c<=k;
        
    }
};