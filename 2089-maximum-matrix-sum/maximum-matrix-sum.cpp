class Solution {
public:
    long long max(long long a, long long b){
        if(a>=b)
        return a;
        return b;

    }
    long long min(long long a, long long b){
        if(a>=b)
        return b;
        return a;

    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         long long neg=0,pos=0;
         long long tn=0;
         long long sn=INT_MIN,sp=INT_MAX;

        for(auto it:matrix){
            for(auto jt:it){
                if(jt<0){
                    tn++;
                    sn=max(sn,jt);
                    neg+=jt;
                }
                else{
                    pos+=jt;
                    sp=min(sp,jt);

                }
            }
        }
        if(tn%2==0)
            return pos-neg;
            // cout<<sn<<" "<<sp<<endl;
        if(abs(sn)<sp){
            return pos-neg+2*sn;
        }
        return pos-neg-2*sp;
    }
};