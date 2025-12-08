class Solution {
public:
    int countTriples(int n) {
        int ic=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(i*i+j*j==k*k){
                        if(i!=j)
                            ic++;
                        ic++;
                    }
                }
            }
        }
        return ic;
    }
};