class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<int, set<int>> u;
        for(int i=0;i<s.size();i++)
            u[s[i]].insert(i);
        int c=0;
        for(int i=0;i<s.size();i++){
            auto &it=u[s[i]];
            int n=s.size(),p=-1;
            auto k=it.find(i);
            if(k!=it.begin())
                p=*prev(k);
            if(next(k)!=it.end())
                n=*next(k);

            c+=(i-p)*(n-i);

        }
        return c;

        
        
    }
};