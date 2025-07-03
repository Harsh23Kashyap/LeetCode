class Solution {
public:
string update(string a, vector<char> letters){
    string ans="";

    for(char ch:a){
        int pos=ch-'a';
        pos=(pos+1)%26;
        ans+=letters[pos];
    }
    return ans;
}
    char kthCharacter(int k) {
        vector<char> letters;

        for(char ch='a';ch<='z';ch++){
            letters.push_back(ch);
        }
        string s="a";
        while(s.size()<k){
            s+=update(s,letters);
        }
        // cout<<s<<endl;
        return s[k-1];
    }
};