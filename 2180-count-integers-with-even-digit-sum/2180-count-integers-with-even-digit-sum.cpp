class Solution {
public:
    int sum(int num)
    {
        int add=0;
        while(num>0)
        {
            int dig=num%10;
            add+=dig;
            num/=10;
        }
        return add;
    }
    int countEven(int num) 
    {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            if(sum(i)%2==0)
                count++;
        }
        return count;
        
    }
};