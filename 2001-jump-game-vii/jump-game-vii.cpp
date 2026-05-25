class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> zero;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '0') {
                zero.push_back(i);
            }
        }
        vector<int> dp(s.size(),-1);
        dp[0]=1;
        int next=1;
        for (int i = 0; i < zero.size(); i++) {
            if(dp[zero[i]]==-1)
            continue;
            int mini = minJump + zero[i];
            int maxi = min((int)s.size() - 1, maxJump + zero[i]);

            int j = lower_bound(zero.begin()+ next, zero.end(), mini) - zero.begin();

            if (j == zero.size() or zero[j] > maxi)
                continue;
            int k = j;
            for (; k < zero.size() and zero[k] <= maxi; k++) {
                dp[zero[k]]=1;
                if (zero[k] == s.size() - 1)
                    return true;
            }
            next=max(next,k);
        }

        return false;
    }
};