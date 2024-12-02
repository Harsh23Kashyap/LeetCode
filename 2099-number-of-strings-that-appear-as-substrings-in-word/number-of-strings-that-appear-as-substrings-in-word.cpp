class Solution {
public:
    int numOfStrings(vector<string>& p, string s) {
        int a = p.size();
        int b=0;
        for(int i =0;i<a;i++){
            if(s.find(p[i])!=string::npos){
                b++;
            }
        }  
        return b;
    }
};