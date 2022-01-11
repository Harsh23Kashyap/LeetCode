class Solution {
public:
    bool checkString(string s) 
    {
        for(int i=s.length()-2;i>=0;i--)
        {
            if(s[i]=='b' && s[i+1]=='a')
                return false;
        }
        return true;
    }
};