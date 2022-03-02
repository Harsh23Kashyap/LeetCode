class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s=="")
            return true;
        int j=0;
        for(int i=0;i<t.length();i++)
        {
            cout<<s[j]<<endl;
            if(t[i]==s[j])
                j++;
            if(j==s.length())
                return true;
        }
        return false;
        
        
    }
};