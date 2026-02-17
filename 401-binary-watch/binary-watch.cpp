class Solution {
public:
int bits(int n){
    int c=0;
    while(n>0){
        n=n&(n-1);
        c++;
    }
    return c;
}
string process(int a, int b){
    string res="";
    res+=to_string(a);
    res+=':';
     if(b<10)
        res+="0"+to_string(b);
    else
     res+=to_string(b);
     return res;

}
    vector<string> readBinaryWatch(int turnedOn) {
         vector<string> ans;
        unordered_map<int,vector<int>> u;
        unordered_map<int,vector<int>> v;

        for(int h=0;h<12;h++)
            u[bits(h)].push_back(h);
        for(int m=0;m<60;m++)
            v[bits(m)].push_back(m);
        
        for(auto it:u){
            int count=it.first; 
            if(v.find(turnedOn-count)!=v.end()){
                for(auto jt:it.second){
                    for(auto mt:v[turnedOn-count]){
                        ans.push_back(process(jt,mt));
                    }
                }
            }
        }
        return ans;
        

    }
};