class Solution {
public:
    int mod=1e9+7;
    int base=31;

    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<int, vector<int>> u;
        long long hash=0,power=1;
        int len=s.size();
        for(int i=0;i<min(len,10);i++){
            hash=(hash*base+(s[i]-'a'+1))%mod;
            if(i<9) 
                power=power*base;
        }

        u[hash].push_back(0);
        unordered_set<string> ans;

        for(int j=10;j<s.size();j++){

            //remove ;
            hash=(hash-(((s[j-10]-'a'+1)*power)%mod+mod))%mod;
            hash=(hash*base+(s[j]-'a'+1))%mod;


            if(u.count(hash)){
                for(auto it:u[hash]){
                    if(s.substr(it ,10)==s.substr(j-10+1,10))
                        ans.insert(s.substr(it ,10));
                }
            }
            u[hash].push_back(j-10+1);




        }
        vector<string> res(ans.begin(),ans.end());
    return res;
        
            }
};