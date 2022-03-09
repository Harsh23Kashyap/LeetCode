class Solution {
public:
    int reachNumber(int target) 
    {
        target=abs(target);
        
        int steps=1;
        int sum=1;
        while(true)
        {
            if(sum>=target and (abs(target-sum))%2==0)
                return steps;
            steps++;
            sum+=steps;
                
        }
        return steps;
        
    }
};