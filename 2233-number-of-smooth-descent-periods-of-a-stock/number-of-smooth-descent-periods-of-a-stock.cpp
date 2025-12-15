class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(-1);
        long long total=0;
        int i=0,j=1;
        while(j<prices.size()){
            if(prices[j]-prices[j-1]==-1){
                j++;
            }
            else{
                long long sz=j-i;
                // cout<<j<<endl;
                total+=sz*(sz+1)/2;
                i=j;
                j++;
            }
        }
        return total;
    }
};

/*
4c1=4
4c2=4,3,/2

*/