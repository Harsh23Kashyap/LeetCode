class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)
        return false;
        int v=0,c=0;
        for(auto it:word){
            if(it>='a' and it<='z'){
                if(it=='a' or it=='e' or it=='i' or it=='o' or it=='u')
                v++;
                else
                c++;
            }
             else if(it>='A' and it<='Z'){
                if(it=='A' or it=='E' or it=='I' or it=='O' or it=='U')
                v++;
                else
                c++;
            }
            else if(it>='0' and it<='9'){
               continue;
            }
            else
            return false;
        }
        return c>0 and v>0;
    }
};