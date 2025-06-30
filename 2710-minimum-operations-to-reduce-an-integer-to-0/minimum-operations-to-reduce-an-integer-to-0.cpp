class Solution {
public:
    int pass(int n, vector<int>& pow){
        if(n==0)
        return 0;
        cout<<n<<endl;
        auto lit=lower_bound(pow.begin(),pow.end(),n)-pow.begin();
        auto hit=lower_bound(pow.begin(),pow.end(),n)-pow.begin();
        if(pow[lit]==n)
            return 1;
        
        return 1+min(pass(n-pow[lit-1],pow),pass(pow[hit]-n,pow));

    }
    int minOperations(int n) {
        vector<int> pow(30,1);

        for(int i=1;i<30;i++){
            pow[i]=pow[i-1]<<1;
        }


        return pass(n,pow);

        
    }
};