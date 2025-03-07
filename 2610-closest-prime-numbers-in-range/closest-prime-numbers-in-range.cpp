class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> se(right+1,-1);
        se[0]=se[1]=0;
        for(int i=2;i<=right;i++){
            if(se[i]==0)continue;
            if(isPrime(i)){
                // cout<<"isprime"<<i<<endl;
                se[i]=1;
                for(int cc=2*i;cc<=right;cc=cc+i){
                    se[cc]=0;
                }
            }
        }
        vector<int>pp;
        for(int i=left;i<=right;i++){
            if(se[i]==1)
            pp.push_back(i);
        }
        for(int i=0;i<pp.size();i++)
        cout<<pp[i]<<endl;
        if(pp.size()<2)
        return {-1,-1};
        int a=pp[0],b=pp[1];
        int diff=b-a;
        for(int i=1;i<pp.size()-1;i++){
            if(pp[i+1]-pp[i]<diff){
                diff=pp[i+1]-pp[i];
                a=pp[i];
                b=pp[i+1];
            }
        }

        return {a,b};
    }

    bool isPrime(int iaa){
        if(iaa==2)return true;
        if(iaa%2==0)
        return false;
        for(int i=3;i<=sqrt(i);i+=2){
            if(iaa%i==0)
            return false;
        }
        return true;
    }
};