class Solution {
public:
    void permute(vector<string>& ans,string s, int i, string temp)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[i]))
        {
            temp=temp+s[i];
            permute(ans,s,i+1,temp);
        }
        else
        {
            char ch=s[i];
            temp=temp+ch;
            permute(ans,s,i+1,temp);
            temp=temp.substr(0,temp.length()-1);
            if(islower(ch))
            {
                ch=(char)toupper(ch);
                temp=temp+ch;
                permute(ans,s,i+1,temp);
            }
            else
            {
                ch=(char)tolower(ch);
                temp=temp+ch;
                permute(ans,s,i+1,temp);
            }
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> ans;
        permute(ans,s,0,"");
        return ans;
        
    }
};