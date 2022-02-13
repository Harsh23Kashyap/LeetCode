class Solution {
public:
    void generateHappy(set<string>& s, string curr, int n)
    {
        if(curr.length()==n)
        {
            s.insert(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(curr[curr.length()-1]!=ch)
                generateHappy(s,curr+ch,n);
        }
        
    }
    string getHappyString(int n, int k) 
    {
        set<string> s;
        for(char ch='a';ch<='c';ch++)
        {
            string ans="";
            ans+=ch;
            generateHappy(s,ans,n);
        }
        
        int i=1;
        for(auto it:s)
        {
            if(i==k)
                return it;
            i++;
        }
        return "";
    }
};