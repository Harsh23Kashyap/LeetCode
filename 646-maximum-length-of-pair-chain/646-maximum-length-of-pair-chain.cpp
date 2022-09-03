class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        vector<int> dp(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<pairs.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0] and dp[i]<1+dp[j])
                    dp[i]=1+dp[j];
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};