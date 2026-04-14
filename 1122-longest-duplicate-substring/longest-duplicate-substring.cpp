class Solution {
public:
string s;
int n;

int base=31;
int mod=1e9+7;
    string possible(int m){
        unordered_map<int, vector<int>> u;
        long long hash=0,power=1;
        for(int i=0;i<m;i++){
            hash=(hash*base+(s[i]-'a'+1))%mod;
            if(i<m-1){
                power=(power*base)%mod;
            }
        }

        u[hash].push_back(0);

        for(int j=m;j<s.size();j++){
            //remove
            hash=(hash-((s[j-m]-'a'+1)*power% mod )+mod)%mod;

            //add
            hash=(hash*base+ ((s[j]-'a'+1)))%mod;

            if(u.count(hash)  ){
                for(auto it:u[hash]){
                    if(s.substr(j-m+1,m)==s.substr(it,m))
                    {
                        return s.substr(it,m);
                    }
                }
                
            }
             u[hash].push_back(j-m+1);

        }
        return "";
    }

    string longestDupSubstring(string ns) {
        s=ns;
        n=s.size();

        int l=1,r=n;
        int ans=1;
        string sans="";
        while(l<=r){
            int m=l+(r-l)/2;
            string check=possible(m);
            if(check!=""){
                sans=check;
                l=m+1;
            }
            else
            r=m-1;
        }
        return sans;
        
    }
};