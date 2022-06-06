class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        if(s.size()<k)
            return false;
        long long high=pow(2,k);
        set<string> sl;
        for(int i=0;i<s.size()-k+1;i++)
        {
            sl.insert(s.substr(i,k));
            if (sl.size()==high)
                return true;
        }
        return false;
        
    }
};