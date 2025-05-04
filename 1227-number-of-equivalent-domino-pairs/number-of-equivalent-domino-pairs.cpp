class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> ul;
        for(auto it:dominoes){
            if(it[0]>it[1]){
                int s=it[0];
                it[0]=it[1];
                it[1]=s;
            }
            pair<int,int> p={it[0],it[1]};
            ul[p]++;
        }
        int c=0;
        for(auto it:ul)
        {
            c+=((it.second*(it.second-1))/2);
        }
        return c;
    }
};