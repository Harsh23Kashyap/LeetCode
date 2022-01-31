class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>who(n+1,0);
        vector<int>whom(n+1,0);
        
        for(auto it:trust)
        {
            who[it[1]]++;
            whom[it[0]]++;
        }
        int ans=-1;
        for(int i=1;i<n+1;i++)
        {
            if(who[i]==n-1 and whom[i]==0) 
                ans = i;
        }
        return ans;
    }
};