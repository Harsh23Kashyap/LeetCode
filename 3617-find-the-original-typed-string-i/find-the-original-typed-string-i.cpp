class Solution {
public:
    int possibleStringCount(string word) {
        word+="/";
        int i=0,j=0;
        int ans=0;
        while(j<word.size()){
            if(word[j]==word[i]){
                j++;
            }
            else{
                ans+=(j-1-i);
                cout<<i<<" "<<j<<endl;
                i=j;
            }
        }
        return ans+1;
    }
};