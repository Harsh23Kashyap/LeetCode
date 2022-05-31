class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        if(k>s.length()) return false;
        int total=pow(2,k);
        set<string> se;
        for(int i=0;i<s.length()-k+1;i++)
        {
            se.insert(s.substr(i,k));
            if(se.size()==total)
                return true;
        }
        return false;
        
    }
};