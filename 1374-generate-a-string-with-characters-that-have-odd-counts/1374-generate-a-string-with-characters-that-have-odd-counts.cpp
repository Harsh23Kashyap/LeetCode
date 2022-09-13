class Solution {
public:
    string generateTheString(int n) 
    {
        if(n%2!=0)
        {
            string s(n,'a');
            return s;
            
        }
        string s(n-1,'a');
        s+='b';
        return s;
        
        
    }
};