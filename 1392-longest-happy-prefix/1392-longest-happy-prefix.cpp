class Solution {
public:
    int lps(string s)
    {
        vector<int> lp(s.size(),0);
        int ind=0;
        for(int i=1;i<s.size();)
        {
            if(s[i]==s[ind])
            {
                ind++;
                lp[i]=ind;
                i++;
            }
            else
            {
                if(ind==0)
                    i++;
                else
                    ind=lp[ind-1];
            }
        }
        // for(int i=0;i<lp.size();i++)
        //     cout<<lp[i]<<" ";
        cout<<endl;
        return lp.back();
    }
    string longestPrefix(string s) {
        return s.substr(0,lps(s));
    }
};