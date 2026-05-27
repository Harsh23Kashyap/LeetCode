class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int, int> low;
        unordered_map<int, int> upper;

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(islower(ch))
                low[ch]=i;
            if(isupper(ch) and upper.find(tolower(ch))==upper.end()){
                    upper[tolower(ch)]=i;
            }

        } 
        int c=0;
        for(char ch='a';ch<='z';ch++){
            if(low.find(ch)!=low.end()){
                if(upper.find(ch)!=upper.end()){
                    if(upper[ch]>=low[ch])
                        c++;
                }
            }
        }
        return c;
    }
};