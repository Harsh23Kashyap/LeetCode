class Solution {
public:
    bool checkStrings(string s1, string s2) {
         
        string n1="",n2="";
        for(int i=0;i<s1.size();i+=2){
            n1+=s1[i];
            n2+=s2[i];
        }
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        if(n1!=n2)
        return false;
        n1="",n2="";
        for(int i=1;i<s1.size();i+=2){
            n1+=s1[i];
            n2+=s2[i];
        }
         sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
       return n1==n2;
    }
};