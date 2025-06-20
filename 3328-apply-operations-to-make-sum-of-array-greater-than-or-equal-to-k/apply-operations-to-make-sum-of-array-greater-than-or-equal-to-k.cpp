class Solution {
public:
    int div(int a, int b)
    {
        return (a+b-1)/b;
    }
    int times(int k, int i){
         int numberOfTimes=div(k,i)-1;
         int AdditionTimes=i-1;
         return numberOfTimes+AdditionTimes;
    }
    int minOperations(int k) {
        
        int mini=k;
        for(int i=1;i<=k;i++){
            int numberOfTimes=div(k,i)-1;
            int AdditionTimes=i-1;
            cout<<numberOfTimes<<" "<<AdditionTimes<<endl;
            mini=min(mini,numberOfTimes+AdditionTimes);
            if(numberOfTimes+AdditionTimes>mini)
                return mini;
        }
       return mini;
    }
};