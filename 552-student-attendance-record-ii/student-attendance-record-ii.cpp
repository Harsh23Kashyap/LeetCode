class Solution {
public:
int m=1e9+7;
    long long pass(int i,int a, int l, vector<vector<vector<long long>>> &dp, int n){
        if(i==n)
            return 1;
        if(dp[i][a][l]!=-1)
        return dp[i][a][l];
        long long c=0;
        if(a<1){
            // string check=s+"A";
            // cout<<check<<endl;
            long long val=pass(i+1,a+1,0,dp,n);
            c+=val;
        }
        if(l<2){
            // string check=s+"L";
            // cout<<check<<endl;
            long long val=pass(i+1,a,l+1,dp,n);
            c+=val;
        }
        // string check=s+"P";
        // cout<<check<<endl;
        long long val=pass(i+1,a,0,dp,n);
        c+=val;
        return dp[i][a][l]=c%m;


    }
    int checkRecord(int n) {
        if(n==1)
        return 3;
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (3,vector<long long> (3,-1)));
        return pass(0,0,0,dp,n)%m;

    }
};