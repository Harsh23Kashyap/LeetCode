class Solution {
public:
    bool checkOnesSegment(string s) {
       
       int c=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            i++;
            c++;
            while(i<s.size() and s[i]=='1'){
                i++;
            }
        }
       }
       return c<=1;
    }
};