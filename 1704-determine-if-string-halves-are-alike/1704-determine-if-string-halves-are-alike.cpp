class Solution {
public:
    bool isVowel(char c)
    {
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) 
    {
        int first=0,sec=0;
        for(int i=0;i<s.length()/2;i++)
        {
            if(isVowel(s[i]))
                first++;
        }
        for(int i=s.length()/2;i<s.length();i++)
        {
            if(isVowel(s[i]))
                sec++;
        }
        return first==sec;
    }
};