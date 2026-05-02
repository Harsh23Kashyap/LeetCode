class Solution {
public:
    int rotatedDigits(int n) {
        int curr=0;

        for(int i=1;i<=n;i++){
            int currnum=i;
            bool changes=false,valid=true;
            while(currnum>0){
                int dig=currnum%10;
                if(dig==3 or dig==7 or dig==4)
                {
                    valid=false;
                    break;
                }
                if(dig==6 or dig==9 or dig==2 or dig==5)
                    changes=true;
                currnum/=10;
            }
            if(valid and changes)
                curr++;
        }
        return curr;
    }
};