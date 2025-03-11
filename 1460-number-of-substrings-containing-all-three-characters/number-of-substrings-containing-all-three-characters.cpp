class Solution {
public:
    int numberOfSubstrings(string st) {
        unordered_map<char,int> u;
        int s=0,e=0;
        int tot=0;
        while(e<st.size()){
            char ch=st[e];
            u[ch]++;

            while(u.size()==3){
                tot+=st.size()-e;
                u[st[s]]-=1;
                if(u[st[s]]<1){
                    u.erase(st[s]);
                }
                s++;
            }
            e++;
        }
        return tot;
    }
};