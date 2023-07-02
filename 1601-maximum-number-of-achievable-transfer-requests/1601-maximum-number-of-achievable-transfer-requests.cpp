class Solution {
public:
    int maxi=0;
        void pass(vector<vector<int>>& requests, int i, int total, vector<int>& dp)
    {
        if(i==requests.size())
        {
            
            for(int i:dp)
            {
                if(i!=0)
                {
                   return;
                }
            }
            maxi=max(maxi,total);
            return;
        }
        
        dp[requests[i][0]]--;
        dp[requests[i][1]]++;
        pass(requests,i+1,total+1,dp);
        dp[requests[i][0]]++;
        dp[requests[i][1]]--;
            pass(requests,i+1,total,dp);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> dp(n,0);
        pass(requests,0,0,dp);
        return maxi;
    }
};