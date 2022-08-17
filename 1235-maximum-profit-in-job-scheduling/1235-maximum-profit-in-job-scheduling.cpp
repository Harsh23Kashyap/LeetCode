class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) 
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        map<int, int> dp;
        dp[0]=0;
        int maxi=0;
        for (auto& it : jobs) 
        {
            int cur = (--dp.upper_bound(it[1]))->second + it[2];
            auto temp=dp.rbegin();
            if (cur > temp->second)
            {
                dp[it[0]] = cur;
                maxi=cur;
            }
        }
        return maxi;
        
    }
};