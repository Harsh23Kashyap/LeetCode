long long dp[30001];
class Solution {
public:
long long help(vector<vector<int>> &ar,int pos){
    int n=ar.size();
    if(pos==n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    // either I attend ar[pos] trip or not
    long long ans=help(ar,pos+1);
    // find the first starting time JUST greater than ending time of ar[pos] in log(n) time using binary search
    int lo=pos+1,hi=n-1,nextPos=n;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(ar[mid][0]>=ar[pos][1]){
            nextPos=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    dp[pos]=max(ans,ar[pos][2]+help(ar,nextPos));
    return dp[pos];
}

long long maxTaxiEarnings(int n, vector<vector<int>>& ar) {
    memset(dp,-1,sizeof(dp));
    for(auto &it:ar) it[2]+=it[1]-it[0];
    sort(ar.begin(),ar.end());
    return help(ar,0);
}
};