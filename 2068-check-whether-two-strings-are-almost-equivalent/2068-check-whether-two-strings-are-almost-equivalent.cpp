class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) 
    {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<word1.size();i++)
            a[word1[i]-'a']++;
        
         for(int i=0;i<word2.size();i++)
            b[word2[i]-'a']++;
        
        int diff=0;
        for(int i=0;i<26;i++)
        {
            if(abs(a[i]-b[i])>3)
                return false;
        }
        return true;
        
    }
};