class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int> u;
        for(auto it:matches)
        {
            int win=it[0];
            int los=it[1];
            if(u.find(win)==u.end())
                u[win]=0;
            if(u.find(los)==u.end())
                u[los]=1;
            else
                u[los]++;
            
        }
        vector<int> win;
        vector<int> lose;
        
        for(auto it:u)
        {
            if(it.second==0)
                win.push_back(it.first);
            if(it.second==1)
                lose.push_back(it.first);
        }
        return {win,lose};
        
    }
};