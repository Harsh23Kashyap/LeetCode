class Solution {
public:
    string sortVowels(string s) {
        string t="";
        string k="";
        for(char ch:s){
            char curr=tolower(ch);
            if(curr=='a' or curr=='e' or curr=='i' or curr=='o' or curr=='u')
                k+=ch;
        }
        sort(k.begin(),k.end());
        int j=0;
        for(char ch:s){
            char curr=tolower(ch);
            if(curr=='a' or curr=='e' or curr=='i' or curr=='o' or curr=='u'){
                t+=k[j++];
            }
            else{
                t+=ch;
            }
        }

        return t;
    }
};