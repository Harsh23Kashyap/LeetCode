class Solution {
public:
    int countOperations(int num1, int num2) {
        int c=0;
        while(num1!=0 and num2!=0){
            // cout<<num1<<" "<<num2<<endl;
            if(num1>num2)
                num1-=num2;
            else
                num2-=num1;
            c++;
        }
        return c;
    }
};