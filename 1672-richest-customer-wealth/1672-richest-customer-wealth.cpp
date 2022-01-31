class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int m=INT_MIN;
        for(int i=0;i<accounts.size();i++)
        {
            m=max(m,accumulate(accounts[i].begin(),accounts[i].end(),0));
        }
        return m;
        
    }
};