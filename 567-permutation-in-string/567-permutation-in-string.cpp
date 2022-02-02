class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.length()>s2.length()) return false;
        unordered_map<char,int> s1map;
        for(char ch='a';ch<='z';ch++)
            s1map[ch]=0;
        
        unordered_map<char,int> s2map;
        for(char ch='a';ch<='z';ch++)
            s2map[ch]=0;
        
        for(int i=0;i<s1.length();i++)
            s1map[s1[i]]++;
        
        int k=s1.length();
        for(int i=0;i<k;i++)
             s2map[s2[i]]++;
        
        bool ans=true;
        for(auto i:s1map)
        {
            if(i.second!=s2map[i.first])
            {
                ans=false;
                break;
            }
        }
        if(ans) return true;
        
        for(int i=k;i<s2.length();i++)
        {
            s2map[s2[i-k]]--;
            s2map[s2[i]]++;
            bool ans=true;
            for(auto i:s1map)
            {
                if(i.second!=s2map[i.first])
                {
                    ans=false;
                    break;
                }
            }
            if(ans) return true;
        }
        return false;
    }
};