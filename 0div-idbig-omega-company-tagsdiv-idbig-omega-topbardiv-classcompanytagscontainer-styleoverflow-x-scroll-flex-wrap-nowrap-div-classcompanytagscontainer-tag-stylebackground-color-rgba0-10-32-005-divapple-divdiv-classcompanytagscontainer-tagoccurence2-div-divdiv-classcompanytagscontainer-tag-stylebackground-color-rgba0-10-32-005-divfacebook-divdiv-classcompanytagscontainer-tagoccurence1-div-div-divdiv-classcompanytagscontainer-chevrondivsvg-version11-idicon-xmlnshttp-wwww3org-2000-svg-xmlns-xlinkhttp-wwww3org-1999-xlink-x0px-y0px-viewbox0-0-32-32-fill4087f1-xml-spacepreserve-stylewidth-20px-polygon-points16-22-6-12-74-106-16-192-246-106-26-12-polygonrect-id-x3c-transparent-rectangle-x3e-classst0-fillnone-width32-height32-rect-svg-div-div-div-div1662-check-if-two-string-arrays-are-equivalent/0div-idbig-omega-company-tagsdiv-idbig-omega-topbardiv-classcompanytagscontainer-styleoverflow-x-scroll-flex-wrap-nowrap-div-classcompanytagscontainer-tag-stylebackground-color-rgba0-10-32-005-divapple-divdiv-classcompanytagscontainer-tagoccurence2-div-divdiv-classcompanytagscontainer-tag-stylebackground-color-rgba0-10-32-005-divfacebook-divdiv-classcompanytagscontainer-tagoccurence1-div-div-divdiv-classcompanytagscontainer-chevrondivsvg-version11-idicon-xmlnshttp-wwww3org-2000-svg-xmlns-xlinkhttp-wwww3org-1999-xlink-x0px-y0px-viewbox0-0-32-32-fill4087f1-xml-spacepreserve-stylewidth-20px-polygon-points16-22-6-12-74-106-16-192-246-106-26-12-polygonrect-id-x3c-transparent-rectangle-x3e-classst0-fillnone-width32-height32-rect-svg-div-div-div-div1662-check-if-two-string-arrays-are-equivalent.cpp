class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string t="",s="";
        for(auto it:word1)
            t+=it;
        for(auto it:word2)
            s+=it;
        return t==s;
    }
};