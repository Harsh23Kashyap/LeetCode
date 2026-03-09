long long dp[201][201][2][201];

class Solution {
public:
    int mod = 1e9+7;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }

    long long nCr(int n,int r){
        long long num=1,den=1;
        for(int i=0;i<r;i++){
            num=num*(n-i)%mod;
            den=den*(i+1)%mod;
        }
        return num*power(den,mod-2)%mod;
    }

    long long pass(int z,int o,int limit,int curr,int last){

        if(z==0 && o==0)
            return 1;

        if(last!=-1 && dp[z][o][last][curr]!=-1)
            return dp[z][o][last][curr];

        long long ans=0;

        // place 0
        if(z>0){
            if(last==0){
                if(curr<limit)
                    ans=(ans+pass(z-1,o,limit,curr+1,0))%mod;
            }else{
                ans=(ans+pass(z-1,o,limit,1,0))%mod;
            }
        }

        // place 1
        if(o>0){
            if(last==1){
                if(curr<limit)
                    ans=(ans+pass(z,o-1,limit,curr+1,1))%mod;
            }else{
                ans=(ans+pass(z,o-1,limit,1,1))%mod;
            }
        }

        if(last!=-1)
            dp[z][o][last][curr]=ans;

        return ans;
    }

    int numberOfStableArrays(int zero,int one,int limit) {

        // shortcut when limit never binds
        if(limit >= max(zero,one))
            return nCr(zero+one,zero);

        memset(dp,-1,sizeof(dp));

        return pass(zero,one,limit,0,-1);
    }
};