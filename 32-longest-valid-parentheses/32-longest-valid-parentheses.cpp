class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<pair<char,int>> st;
        int curr=0;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() or s[i]=='(')
            {
                st.push(make_pair(s[i],i));
            }
            else if(s[i]==')')
            {
                if(st.top().first=='(')
                {
                    st.pop();
                    if(st.empty())
                        curr=max(curr,i+1);
                    else
                        curr=max(curr,i-st.top().second);
                    
                }
                else
                {
                    st.push(make_pair(s[i],i));
                }
            }
        }
        return curr;
        
    }
};