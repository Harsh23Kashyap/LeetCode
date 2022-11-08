class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            bool found=false;
            if(!st.empty())
            {
                char t=st.top();
                if(char(t+32)==s[i] or char(t-32)==s[i])
                {
                    found=true;
                    //cout<<t<<endl;
                    st.pop();
                }
            }
            if(found==false)
                st.push(s[i]);
        }
        string a="";
        while(!st.empty())
        {
            char ch=st.top();
            st.pop();
            a=ch+a;
        }
        return a;
        
    }
};