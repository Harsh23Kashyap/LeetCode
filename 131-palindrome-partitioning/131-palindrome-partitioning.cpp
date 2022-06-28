class Solution {
public:
    void subset(string s,int ind, vector<vector<string>>& ans, vector<string> &temp)
    {
        if(ind==s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(palin(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                subset(s,i+1,ans,temp);
                temp.pop_back();
                
            }
        }
    }
    bool palin(string s, int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        
        subset(s,0,ans,temp);
        return ans;
    }
};