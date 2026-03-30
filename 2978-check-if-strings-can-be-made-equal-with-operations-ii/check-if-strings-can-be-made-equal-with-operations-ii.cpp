class Solution {
public:
    bool pass(string s1, string s2,int i){
        string n1="",n2="";
        for(int j=i;j<s1.size();j+=2){
            n1+=s1[j];
            n2+=s2[j];
        }
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        return n1==n2;
    }
    bool checkStrings(string s1, string s2) {    
     return pass(s1,s2,0) and pass(s1,s2,1); 
    }
};