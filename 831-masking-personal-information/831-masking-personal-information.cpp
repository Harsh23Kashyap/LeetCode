class Solution {
public:
    string maskPII(string s) 
    {
        string ans="";
        if(isalpha(s[0]))
        {
            char ch=tolower(s[0]);
            ans=ans+ch+"*****";
            char last;
            int i;
            for(i=1;i<s.length();i++)
            {
                if(s[i]=='@')
                    break;
                last=s[i];
            }
            ch=tolower(last);
            ans=ans+ch+"@";
            for(int j=i+1;j<s.length();j++)
            {
                ch=tolower(s[j]);
                ans=ans+ch;
            }
            return ans;
        }
        else
        {
            string dig="";
            for(int i=0;i<s.length();i++)
            {
                if(isdigit(s[i]))
                    dig+=s[i];
            }
            int diglen=dig.length();
            dig=dig.substr(diglen-4);
            if(diglen==10)
                ans+="***-***-"+dig;
            else if(diglen==11)
                ans+="+*-***-***-"+dig;
            else if(diglen==12)
                ans+="+**-***-***-"+dig;
            else
                ans+="+***-***-***-"+dig;
        }
        return ans;
    }
};