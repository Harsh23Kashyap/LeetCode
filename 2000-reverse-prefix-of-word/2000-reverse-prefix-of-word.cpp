class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        size_t found = word.find(ch);
        if (found == string::npos) return word;
        string prefix=word.substr(0,found+1);
        reverse(prefix.begin(),prefix.end());
        //cout<<prefix;
        return prefix+word.substr(found+1);
    }
};