class Solution {
public:
    bool doesAliceWin(string s) {
        for(char ch:s){
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
                return true;
        }
        return false;
    }
};