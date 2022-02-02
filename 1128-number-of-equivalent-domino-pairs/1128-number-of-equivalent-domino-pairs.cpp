class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        map<vector<int>, int> u;
        for(int i=0;i<dominoes.size();i++)
        {
            sort(dominoes[i].begin(),dominoes[i].end());
            u[dominoes[i]]++;
        }
        int c=0;
        for(auto i:u)
            c+=(i.second*(i.second-1)/2);
        return c;
        
    }
};