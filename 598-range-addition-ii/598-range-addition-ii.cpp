class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        
        int mini=m;
        int maxi=n;
        for(vector<int> i:ops)
        {
            mini=min(mini,i[0]);
            maxi=min(maxi,i[1]);
        }
        return mini*maxi;
    }
};