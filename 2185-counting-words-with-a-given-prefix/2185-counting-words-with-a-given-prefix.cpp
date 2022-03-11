class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int len=pref.length();
        int count=0;
        for(string s:words)
        {
            if(s.substr(0,len)==pref)
                count++;
        }
        return count;
        
    }
};