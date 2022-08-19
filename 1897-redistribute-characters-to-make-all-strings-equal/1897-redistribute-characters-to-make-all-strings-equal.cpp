class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        vector<int> cha(26,0);
        for(string s:words)
        {
            for(char ch:s)
                cha[ch-'a']++;
        }
        for(int i=0;i<cha.size();i++)
        {
            if(cha[i]%words.size()!=0)
                return false;
        }
        return true;
        
    }
};