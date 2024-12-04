class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int j=0,i=0;
        while(j<str2.size() and i<str1.size())
        {
                if(str2[j]==str1[i]){
                    j++;
                    i++;
                }
                else if (str2[j]-str1[i]==1 or (str2[j]=='a' and str1[i]=='z'))
                {
                    j++;
                    i++;
                }
                else{
                i++;
                }
        }
        return j==str2.size();
    }
};