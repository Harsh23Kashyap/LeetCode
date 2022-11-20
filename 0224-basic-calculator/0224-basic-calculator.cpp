class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        int res=0,sign=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                continue;
            else if(isdigit(s[i]))
            {
                int num=s[i]-'0';
                while(i+1<s.size() and isdigit(s[i+1]))
                {
                    i++;
                    num=num*10+(s[i]-'0');
                    //i++;
                }
                res+=num*sign;
                //cout<<num<<endl;
            }
            
            else if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=-1;
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                int xsign=st.top();
                st.pop();
                int xnum=st.top();
                st.pop();
                
                res=res*xsign+xnum;
                
            }
            //cout<<res<<".  "<<endl;
        }
        return res;
        
    }
};