class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> u(brokenLetters.begin(),brokenLetters.end());
        int c=0;
        stringstream ss(text);

        string temp;
        while(ss>> temp){
            bool type=true;
            for(char ch:temp){
                if(u.find(ch)!=u.end()){
                    type=false;
                    break;
                }
            }
            if(type)
                c++;
        }
        return c;
    }
};