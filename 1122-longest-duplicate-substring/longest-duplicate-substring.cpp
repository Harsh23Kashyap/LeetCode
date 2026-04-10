class Solution {
public:
string s;
int mod=1e9+7;
int n;
int base=31;

    string check(int m){

        unordered_map<long long, vector<int>> mp;

        long long hash=0,power=1;

        //window1;
        for(int i=0;i<m;i++){
            hash=(hash*base + (s[i]-'a'+1))%mod;
            if(i<m-1)
                power=(power*base)%mod;
        }


        mp[hash].push_back(0);

        for(int i=m;i<s.size();i++){
            hash=(hash-(s[i-m]-'a'+1)*power % mod + mod)%mod;

             hash=(hash*base + (s[i]-'a'+1))%mod;

             int start=i-m+1;

             if(mp.count(hash)){
                for(int prevStart:mp[hash]){
                    if(s.substr(prevStart,m)==s.substr(start,m)){
                        return s.substr(prevStart,m);
                    }
                }
             }

             mp[hash].push_back(start);




        }

        return "";

    }
    string longestDupSubstring(string str) {
        s=str;
        int l=1, r=s.size();
         n=s.size();
        string ans="";
        while(l<=r){
            int m=l+(r-l)/2;
             string cans=check(m);
            if(cans=="")
                r=m-1;
            else{
                l=m+1;
                ans=cans;
            }
        }
        return ans;
    }
};