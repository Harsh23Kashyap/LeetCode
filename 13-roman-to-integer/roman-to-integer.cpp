class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map<string,int> u;
        u["I"]=1;
        u["IV"]=4;
        u["V"]=5;
        u["IX"]=9;
        u["X"]=10;
        u["XC"]=90;
        u["C"]=100;
        u["XL"]=40;
        u["L"]=50;
        u["CD"]=400;
        u["D"]=500;
        u["CM"]=900;
        u["M"]=1000;

        for(int i=0;i<s.size();i++){
            string curr="";
            curr+=s[i];
            bool wedid=false;
            if(i+1<s.size()){
                string nex=curr+s[i+1];
                if(u.count(nex)){
                    i++;
                    wedid=true;
                    sum+=u[nex];
                }
            }
            if(!wedid){
                sum+=u[curr];
            }
            
        }
        return sum;
    }
};