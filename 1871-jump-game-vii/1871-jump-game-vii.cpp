class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n=s.size();
        vector<bool> dp(n,false);
        if(s[n-1]=='1')
            return false;
        dp[0]=true;
        int currzero=0;
        for(int i=1;i<n;i++)
        {
            if(i-minJump>=0 and dp[i-minJump]==true)
                currzero++;
             if(i-maxJump-1>=0 and dp[i-maxJump-1]==true)
                currzero--;
            
            dp[i]=((currzero>0) and s[i]=='0');
        }
        return dp[n-1];
    }
};