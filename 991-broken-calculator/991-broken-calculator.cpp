class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count=0;
        if(target<=startValue)
            return abs(target-startValue);
        //cout<<target<<endl;
        while(target!=startValue)
        {
            count++;
            if(target<startValue)
                target++;
            else if(target%2!=0)
                target++;
            else
                target/=2;
            //cout<<target<<endl;
            
        }
        return count;
    }
};