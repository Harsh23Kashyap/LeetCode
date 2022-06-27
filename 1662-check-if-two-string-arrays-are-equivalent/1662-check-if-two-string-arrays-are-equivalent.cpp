class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s="";
        for(string temp1:word1)
            s+=temp1;
        string t="";
        for(string temp2:word2)
            t+=temp2;
        return t==s;
        
    }
};