class Solution {
public:
    int countSubstrings(string s) {
        int c=0;

        for(int i=0;i<s.size();i++){

            int j=i,k=i;
            while(j>=0 and k<s.size()){
                if(s[j]==s[k]){
                    c++;
                }
                else{
                    break;
                }
                j--,k++;
            }
            j=i,k=i+1;
            while(j>=0 and k<s.size()){
                if(s[j]==s[k]){
                    c++;
                }
                else{
                    break;
                }
                j--,k++;
            }


        }
        return c;
    }
};