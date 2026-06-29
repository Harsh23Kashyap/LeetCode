class Solution {
public:
bool there(string a, string b){

    auto it=b.find(a);
    if(it==string::npos)
        return false;
    return true;
}
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;

        for(int i=0;i<patterns.size();i++){
            if(there(patterns[i],word)){
                c++;
            }
        }
        return c;
    }
};