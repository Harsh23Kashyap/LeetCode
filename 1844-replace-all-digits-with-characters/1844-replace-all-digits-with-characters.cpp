class Solution {
public:
    string replaceDigits(string s) 
    {
        for(int i=1;i<s.size();i+=2)
        {
            int ch=s[i-1]-'a';
            int dig=s[i]-'0';
            ch=(ch+dig)%26 + 97;
            s[i]=char(ch);
            
        }
        return s;
        
    }
};