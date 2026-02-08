class Solution {
public:
    bool possible(string s, int i, unordered_set<string> uu,vector<int> &dp ){
        if(i==s.size())
        return true;
        if(dp[i]!=-1)
        return dp[i];
        for(int j=i+1;j<=s.size();j++){
            string curr=s.substr(i,j-i);
            if(uu.find(curr)!=uu.end() and possible(s,j,uu,dp))
                return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        unordered_set<string> uu(wordDict.begin(),wordDict.end());
        return possible(s,0,uu,dp);
    }
};