class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        unordered_map<char,int> count;
        unordered_map<char,bool> visit;
        
        for(int i=0;i<s.length();i++)
        {
            count[s[i]]++;
            visit[s[i]]=false;
        }
        
        
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            
            char ch=s[i];
            //cout<<"\nCurrent char - "<<ch<<endl;
            count[ch]--;
            if(visit[ch]==false)
            {
                while(!st.empty() and st.top()>s[i] and count[st.top()]!=0)
                {
                    //cout<<"Pop "<<st.top()<<endl;
                    visit[st.top()]=false;
                    st.pop();
                }
                
            st.push(ch);
                
            visit[ch]=true;
            }
        }
        
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
            
        }
        return ans;
        
        
        
    }
};