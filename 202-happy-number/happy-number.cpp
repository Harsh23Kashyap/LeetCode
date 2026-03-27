class Solution {
public:
     long long square(int a){
        long long l=0;
        while(a>0){
             long long dig=a%10;
            l=l+dig*dig;
            a/=10;

        }
        return l;
    }
    bool isHappy(int a) {
         long long slow=a,fast=a;
        do{
              slow=square(slow);
              fast=square(square(fast));
              cout<<slow<<" "<<fast<<endl;
        }while(slow!=fast);
        return slow==1;        
    }
};