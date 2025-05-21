class Solution {
public:
bool possible(string s, string c){

    int i=0,j=0;
    while(i<s.size() and j<c.size()){
        if(s[i]==c[j]){
            i++,j++;
        }
        else{
            j++;
        }
    }
    return i==s.size();
}
    string findLongestWord(string s, vector<string>& dictionary) {
        string curr="";
        for(auto it: dictionary){
            if(possible(it,s)){
                if(it.size()>curr.size()){
                    curr=it;
                }
                else if(it.size()==curr.size()){
                    curr=(it<curr)?it:curr;
                }
            }
        }
        return curr;
    }
};