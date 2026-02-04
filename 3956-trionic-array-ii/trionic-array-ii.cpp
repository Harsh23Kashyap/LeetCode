class Solution {
public:
typedef long long ll;
long long inf=-1e13;
long long illegalstate=-4e15;
int n=0;
    ll dfs(int st, vector<int>& nums,  vector<vector<ll>> &dp, int i){

        if(i==n){
            if(st!=3)
                return illegalstate;
            return 0;
        }
        if(st>3)
            return 0;
        if (i+1 < n and nums[i] == nums[i+1]) {
            if (st == 3) 
                return nums[i]; 
            if(st==1 or st==2)
                return illegalstate;     
        }

        //pruning check. if i am at 2nd last element then max i can hve is 1 transition basically nums.size()-1-i>=k where is k is no of state to still do 3-st
        if(!(n-i-1>=3-st))
            return illegalstate;
        if(dp[i][st]==illegalstate)
        return illegalstate;
        if(dp[i][st]!=inf)
            return dp[i][st];
        //options i have is 
        //i skip if state is 0

        ll res=illegalstate;
        if(st==0){
            res=max(res,dfs(0,nums,dp, i+1));
        }
        //what if we wanna start from here
        if(st==0){
            if(i+1<n and nums[i]<nums[i+1]){
                res=max(res,nums[i]+dfs(1,nums,dp, i+1));
            }
        }
        //if sttae=1,then i check to whether ocntinue or stop
        if(st==1){

            //if next number greater continue;
            if(i+1<n and nums[i]<nums[i+1]){
                res=max(res,nums[i]+dfs(1,nums,dp, i+1));
            }
            //if smaller move to next state
            else if(i+1<n and nums[i]>nums[i+1]){
                res=max(res,nums[i]+dfs(2,nums,dp, i+1));
            }
            else{
                //we reached end in first only, not possible state 
                return illegalstate;
            }
        }
        //if sttae=2,then i check to whether ocntinue or stop
        else if(st==2){

            //if next number greater continue;
            if(i+1<n and nums[i]>nums[i+1]){
                res=max(res,nums[i]+dfs(2,nums,dp, i+1));
            }
            //if greater move to next state
            else  if(i+1<n and nums[i]<nums[i+1]){
                res=max(res,nums[i]+dfs(3,nums,dp, i+1));
            }
             else{
                //we reached end in first only, not possible state 
                return illegalstate;
            }
        }
        else if(st==3){
             //if next number greater continue;
            if(i+1<n and nums[i]<nums[i+1]){
                res=max(res,nums[i]+dfs(3,nums,dp, i+1));
            }
            //if smaller move to next state we cant so ed here, we can also terminate here
            res=max(res,1ll*nums[i]+0);
            
        }
        // cout<<"For dp "<<i<<" state "<<st<<" val is "<<res<<endl;
        return dp[i][st]=res;
    }

    long long maxSumTrionic(vector<int>& nums) {
        n=nums.size();
        vector<vector<ll>> dp(n+1, vector<ll> (4,inf));

        return dfs(0,nums,dp, 0);
    }
};