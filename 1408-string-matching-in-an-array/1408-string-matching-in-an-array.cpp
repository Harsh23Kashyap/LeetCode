class Solution {
public:
    bool check(string p, string s)
    {
        int l=p.size();
        for(int i=0;i+l<=s.size();i++)
        {
            if(s.substr(i,l)==p)
                return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words)
    {
         set<string> ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(words[i].size()<=words[j].size() and i!=j)
                {
                    if(check(words[i],words[j]))
                    {
                        //cout<<i<<" - "<<j<<endl;
                        ans.insert(words[i]);
                       // break;
                    }

                }
            }
        }
        vector<string> fin(ans.begin(),ans.end());
        return fin;
    }
};