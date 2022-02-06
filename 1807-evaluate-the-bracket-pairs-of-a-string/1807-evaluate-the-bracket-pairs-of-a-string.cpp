class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) 
    {
        unordered_map<string,string> u;
        for(int i=0;i<knowledge.size();i++)
            u[knowledge[i][0]]=knowledge[i][1];
        
        string ans="";
        //bool open= false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                string key="";
                i++;
                while(i<s.length() and s[i]!=')')
                {
                    key+=s[i];
                        i++;
                }
                auto it=u.find(key);
                if(it!=u.end())
                    ans+=u[key];
                else
                    ans+='?';
                
            }
            else
                ans+=s[i];
            
        }
        return ans;
        
    }
};