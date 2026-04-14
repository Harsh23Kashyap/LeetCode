class Solution {
public:
    int pass(int i, string s, vector<int> &dp){
        if(i==s.size())
            return 0;
        if(i==s.size()-1)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        
        vector<int> freq(26,0);
        unordered_map<int,int> u;
        int res=INT_MAX;
        for(int k=i;k<s.size();k++){
            int cf= freq[s[k]-'a'];
            if(u.find(cf)!=u.end())
            {
                u[cf]--;
                if(u[cf]==0)
                    u.erase(cf);
            }
            freq[s[k]-'a']++;
            u[freq[s[k]-'a']]++;
            if(u.size()!=1)
                continue;
            
            res=min(res,1+pass(k+1,s,dp));

        }
        return dp[i]=res;
    }
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size(),-1);
        return pass(0,s,dp);

    }
};