class Solution {
public:
    bool check(unordered_set<string>& u, string s, int i, vector<int>& dp){
        if (i == s.size()) return true;
        if(dp[i]!=-1)
        return dp[i];
        for(int j=i+1;j<=s.size();j++){
            string curr=s.substr(i,j-i);
            // cout<<curr<<endl;
            if(u.find(curr)!=u.end() and check(u,s,j,dp))
            return dp[i]=true;
        }
        return  dp[i]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> u(words.begin(),words.end());

         vector<string> ans;

         for(int i=0;i<words.size();i++){
            vector<int> dp(words[i].size()+1,-1);
            u.erase(words[i]);
            if(check(u,words[i],0,dp))
            ans.push_back(words[i]);
            u.insert(words[i]);
         }
         return ans;
    }
};