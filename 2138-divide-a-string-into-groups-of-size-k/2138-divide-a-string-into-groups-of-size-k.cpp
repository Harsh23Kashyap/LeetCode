class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string> v;
        string t;
        for(int i=0;i<s.length();i+=k)
        {
            t=s.substr(i,k);
            if(t.length()==k)
                v.push_back(t);
            else
            {
                int diff=k-t.length();
                string b(diff, fill);
                t+=b;
                v.push_back(t);
            }
        }
        return v;
        
    }
};