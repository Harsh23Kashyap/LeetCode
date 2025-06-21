class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> u;
        int n=s.size();
        for(char ch:s){
           u[ch]++;
        }
        vector<pair<int,char>> vv;
        for(auto it:u){
            vv.push_back({it.second,it.first});
        }

        
       sort(vv.rbegin(),vv.rend());

       if (vv[0].first > (n + 1) / 2)
            return "";

        string a(n, ' ');

        int even=0,odd=1;
        for(int i=0;i<vv.size();i++){
            int freq=vv[i].first;
            char ch=vv[i].second;
            while(even<a.size() and freq>0){
                a[even]=ch;
                freq--;
                even+=2;
            }
            if(even>=a.size()){
            while(odd<a.size() and freq>0){
                a[odd]=ch;
                freq--;
                odd+=2;
            }
        }
        }
        return a;

    }
};