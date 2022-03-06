class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        
        
        for(int i=0;i<words.size();i++)
        {
            string t=words[i];
            unordered_map<char,char> u;
            for(char c:pattern)
                u[c]='\0';
            bool match=true;
            for(int i=0;i<t.length();i++)
            {
                char curr=pattern[i];
                if(u[curr]=='\0')
                    u[curr]=t[i];
                if(u[curr]!=t[i])
                {
                    match= false;
                    break;
                }
            }
            if(!match) continue;
            unordered_map<char,char> u2;
            for(char c:t)
                u2[c]='\0';

            for(int i=0;i<pattern.length();i++)
            {
                char curr=t[i];
                if(u2[curr]=='\0')
                    u2[curr]=pattern[i];
                if(u2[curr]!=pattern[i])
                 {
                    match= false;
                    break;
                }
            }
            if(match)
            {
                ans.push_back(t);
            }
        
        
        }
        return ans;
        
    }
};