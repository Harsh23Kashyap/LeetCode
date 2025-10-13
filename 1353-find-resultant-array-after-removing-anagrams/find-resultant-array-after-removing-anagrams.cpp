class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<vector<int>> dp(words.size(), vector<int> (26,0));

        for(int i=0;i<words.size();i++){
            for(char ch:words[i]){
                dp[i][ch-'a']++;
            }
        }
        vector<string> ans;
        int hero=0;
        ans.push_back(words[hero]);
        for(int i=1;i<words.size();i++){
            while(i<words.size()){
                if(dp[hero]==dp[i])
                i++;
                else
                break;
            }
            if(i<words.size()){
                hero=i;
                ans.push_back(words[hero]);

            }
        }
        return ans;
    }
};