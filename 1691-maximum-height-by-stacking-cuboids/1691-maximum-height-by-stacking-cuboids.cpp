class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        for(int i=0;i<cuboids.size();i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        vector<int> dp(cuboids.size(),0);
        for(int i=0;i<cuboids.size();i++)
        {
            dp[i]=cuboids[i][2];
            for(int j=i-1;j>=0;j--)
            {
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2] )
                    dp[i]=max(dp[i],cuboids[i][2]+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};