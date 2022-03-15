class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                ans+=s[i];
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                    ans+=s[i];
                }
            }
            else
            {
                ans+=s[i];
            }
                
        }
        int count=st.size();
        int j=ans.length()-1;
        for(int i=ans.length()-1;i>=0;i--)
        {
            if(ans[i]=='(' and count-->0)
                continue;
            else
                ans[j--]=ans[i];
        }
        return ans.substr(j+1);
        
    }
};