class Solution {
public: 
    int use(vector<int> a, vector<int> b){
        int sc=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
                sc++;
        }
        return sc;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int sz=students.size();
        int len=students[0].size();
        int full=1<<sz;
        vector<int> dp(full,-1e9);
        dp[0]=0;

        for(int mask=0;mask<full;mask++){
            int i=__builtin_popcount(mask);
            for(int k=0;k<sz;k++){
                if((mask&(1<<k))==0)
                {
                    int newmask=mask | (1<<k);
                    dp[newmask] = max(dp[newmask], dp[mask] + use(students[i],mentors[k]));
                    cout<<dp[newmask]<<endl;
                }
            }
        }
     return dp[full-1];
    }
};
