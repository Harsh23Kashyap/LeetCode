class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        vector<long long> shi(shifts.size(),0);
        shi[shifts.size()-1]=shifts[shifts.size()-1];
        for(long i=shifts.size()-2;i>=0;i--)
            shi[i]=shi[i+1]+shifts[i];
        
        string res="";
        for(int i=0;i<s.size();i++)
        {
            int ch=int(s[i])-'a';
            
            ch=(ch+shi[i])%26 +97;
            res.push_back(char(ch));
            
            
        }
        return res;
        
    }
};