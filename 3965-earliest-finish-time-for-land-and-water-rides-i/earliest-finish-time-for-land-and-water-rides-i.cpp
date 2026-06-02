class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                 
                int landFinish = landStartTime[i] + landDuration[i];
                int total1 = max(landFinish, waterStartTime[j]) +
                             waterDuration[j];
 
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int total2 = max(waterFinish, landStartTime[i]) +
                             landDuration[i];

                ans = min(ans, min(total1, total2));
            }
        }

        return ans;
    }
};