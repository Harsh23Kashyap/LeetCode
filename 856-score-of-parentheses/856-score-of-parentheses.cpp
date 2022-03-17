class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        s='('+s+')';
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(-1);
            }
            else
            {
                if(st.top()==-1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int score=0;
                    while(st.top()!=-1)
                    {
                        score+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*score);
                }
            }
        }
        //cout<<"Runs"<<endl;
        return st.top()/2;
        
    }
};