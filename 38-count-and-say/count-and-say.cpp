class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";

        string s=countAndSay(n-1);
        string res="";
        int c=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])
                c++;
            else
            {
                res= res+to_string(c)+s[i-1];
                c=1;
            }
        }
        res= res+to_string(c)+s.back();
        return res;
    }
};