class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long INF=1e15;
        vector<vector<long long>> dp(26, vector<long long> (26,INF));
        for(int i=0;i<dp.size();i++)
        dp[i][i]=0;

        for(int i=0;i<original.size();i++){
            int ind1=original[i]-'a';
            int ind2=changed[i]-'a';;
            dp[ind1][ind2]=min(dp[ind1][ind2],1ll*cost[i]);

        }


       for (int k = 0; k < dp.size(); k++) {
            for (int i = 0; i < dp.size(); i++) {
                for (int j = 0; j < dp.size(); j++) {
                    if (dp[i][k] != INF and dp[k][j] != INF) {
                        if( dp[i][k] + dp[k][j]< dp[i][j]){
                        dp[i][j] =  dp[i][k] + dp[k][j];
                        }
                    }
                }
            }
        }

        long long cost1=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i])
            continue;
              int ind1=source[i]-'a';
            int ind2=target[i]-'a';
            if(dp[ind1][ind2]==INF)
            return -1;
            // cout<<source[i]<<" - "<<target[i]<<"  ->"<<cost1<<endl;
            cost1+=dp[ind1][ind2];
            

        }
        return cost1;
    }
};