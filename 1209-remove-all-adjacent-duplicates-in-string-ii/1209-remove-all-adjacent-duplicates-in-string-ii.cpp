class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++)
        {
           if(st.empty())
               st.push({s[i],1});
            else
            {
                 pair<char,int> p=st.top();
                if(p.first!=s[i])
                    st.push({s[i],1});
                else
                {
                    st.pop();
                    if(p.second+1!=k)
                        st.push({p.first,p.second+1});
                        
                }
            }
        }
        cout<<st.size()<<endl;
        string ans="";
        while(!st.empty())
        {
           string temp="";
            temp.append(st.top().second,st.top().first);
            ans=temp+ans;
            st.pop();
        }
        return ans;
    }
};