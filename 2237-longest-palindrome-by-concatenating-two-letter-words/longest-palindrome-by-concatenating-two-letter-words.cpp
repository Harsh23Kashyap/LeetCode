class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len=0;
        unordered_map<string,int> uu;
        for(auto it:words){
            uu[it]++;
        }
        unordered_set<string> au;
        bool used=false;
        for(auto k:uu)
        {
            string it=k.first;
            if(au.find(it)!=au.end())
            continue;
            if(it[0]==it[1]){
                int all=k.second/2;
                int rem=k.second%2;
                 len=len+2*2*all;
                au.insert(it);
                if(rem>0 and used==false){
                    used=true;
                    len+=2;
                }

            }
            else{
                cout<<it<<endl;
                string opp=k.first;
                swap(opp[0],opp[1]);
                cout<<opp<<endl;
                if(uu.find(opp)!=uu.end()){
                    int freq=min(uu[opp],uu[it]);
                    len=len+2*2*freq;
                    au.insert(opp);
                    au.insert(it);
                }
            }
        }
        return len;
       
    }
};