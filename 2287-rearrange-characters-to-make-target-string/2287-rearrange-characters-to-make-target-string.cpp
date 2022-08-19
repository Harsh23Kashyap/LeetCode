class Solution {
public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char,int> t;
        for(char ch:target)
            t[ch]++;
        unordered_map<char,int> st;
        for(char ch:s)
            st[ch]++;
        
        int mini=INT_MAX;
        for(auto it:t)
        {
            if(st.find(it.first)==st.end())
                return 0;
            mini=min(mini,st[it.first]/it.second);
        }
        
        return mini;
    }
};