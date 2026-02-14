class Solution {
public:
    
    vector<int> sortedIndex;
    
    static bool compareIndex(int a, int b,
                             vector<int>& startTime) {
        return startTime[a] < startTime[b];
    }
    
    void sortJobs(vector<int>& startTime) {
        int n = startTime.size();
        sortedIndex.resize(n);
        
        for(int i = 0; i < n; i++)
            sortedIndex[i] = i;
        
        sort(sortedIndex.begin(), sortedIndex.end(),
             [&](int a, int b) {
                 return startTime[a] < startTime[b];
             });
    }
    
    int findNext(int pos,
                 vector<int>& startTime,
                 vector<int>& endTime)
    {
        int left = pos + 1;
        int right = sortedIndex.size() - 1;
        int ans = sortedIndex.size();
        
        int currentEnd = endTime[sortedIndex[pos]];
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(startTime[sortedIndex[mid]] >= currentEnd) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
    
    int solve(int pos,
              vector<int>& startTime,
              vector<int>& endTime,
              vector<int>& profit,
              vector<int>& dp)
    {
        if(pos >= sortedIndex.size())
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int skip = solve(pos + 1, startTime, endTime, profit, dp);
        
        int nextPos = findNext(pos, startTime, endTime);
        
        int take = profit[sortedIndex[pos]] +
                   solve(nextPos, startTime, endTime, profit, dp);
        
        if(take > skip)
            dp[pos] = take;
        else
            dp[pos] = skip;
        
        return dp[pos];
    }
    
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit)
    {
        int n = startTime.size();
        
        sortJobs(startTime);
        
        vector<int> dp(n, -1);
        
        return solve(0, startTime, endTime, profit, dp);
    }
};
