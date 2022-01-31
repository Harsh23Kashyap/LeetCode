class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    string reverseVowels(string s) 
    {
        int start=-1,end=-1;
        string curr="";
        for(int i=0;i<s.length();i++)
        {
            if(isVowel(s[i]))
                curr+=s[i];
        }
        reverse(curr.begin(),curr.end());
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=curr[j++];
            }
        }
        return s;
        
    }
};