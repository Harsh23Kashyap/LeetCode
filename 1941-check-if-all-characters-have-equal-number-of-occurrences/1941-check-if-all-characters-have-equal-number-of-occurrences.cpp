class Solution {
public:
    bool areOccurrencesEqual(string s) 
    {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        
        int store=0,c=0;
        for(auto it:m)
        {
            if(c==0)
            {
                c=1;
                store=it.second;
            }
            else
            {
                if(it.second!=store)
                    return false;
                else
                {
                    store=it.second;
                }
            }
        }
        return true;
        
    }
};