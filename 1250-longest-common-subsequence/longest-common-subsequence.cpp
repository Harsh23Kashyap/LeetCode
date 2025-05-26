class Solution {
public:
    int longestPossible(vector<vector<int>>& dp, string &t1,string &t2,int i,int j){
        if(i==t1.size() or j==t2.size())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int ans=0;
        if(t1[i]==t2[j])
            ans=1+longestPossible(dp,t1,t2,i+1,j+1);
        if(i+1<t1.size())
        ans=max(ans,longestPossible(dp,t1,t2,i+1,j));
        if(j+1<t2.size())
        ans=max(ans,longestPossible(dp,t1,t2,i,j+1));
        return dp[i][j]=ans;

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int> (text2.size(),-1));

        return longestPossible(dp,text1,text2,0,0);

    }
};