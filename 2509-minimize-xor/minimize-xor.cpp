class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sb=0;
        int tb=0;
        while(num2>0)
        {
            sb++;
            num2=num2&(num2-1);
        }
        cout<<"set bits - "<<sb<<endl;
        num2=num1;
        while(num2>0)
        {
            tb++;
            num2=num2&(num2-1);
        }
        cout<<"set bits - "<<tb<<endl;
    int diff=abs(tb-sb);
        if(tb==sb)
        return num1;

        int x=0;
        if(tb<sb){
            for(int i=0;i<32;i++)
            {
                    if(num1&1){
                        x=x|(1<<i);
                    }
                    else {
                        if(diff>0){
                            x= x| (1<<i);
                            diff--;
                        }
                    }
                    num1=num1>>1;
                cout<<x<<endl;
                
            }
        }
        else{
            while(diff>0){
            num1= num1&(num1-1);
            diff--;
            }
            return num1;
            }
        
        return x;
    }
};

/*
1111
0011

011
111

1100
0001
*/