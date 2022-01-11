class Solution {
public:
    bool checkString(string s) 
    {
        size_t found = s.find("ba");
        if (found != string::npos)
            return false;
        return true;
        
    }
};