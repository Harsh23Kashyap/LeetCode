class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1,j=b.size()-1;
        int c=0;
        while(i>=0 and j>=0){
           int sum=(a[i]-'0')+(b[j]-'0')+c;
           if(sum==3){
            c=1;
            ans="1"+ans;
           }
           if(sum==2){
             c=1;
            ans="0"+ans;
           }
           if(sum==1){
             c=0;
            ans="1"+ans;
           }
            if(sum==0){
             c=0;
            ans="0"+ans;
           }
           i--,j--;
        }
         while(i>=0 ){
           int sum=(a[i]-'0')+c;
           if(sum==3){
            c=1;
            ans="1"+ans;
           }
           if(sum==2){
             c=1;
            ans="0"+ans;
           }
           if(sum==1){
             c=0;
            ans="1"+ans;
           }
            if(sum==0){
             c=0;
            ans="0"+ans;
           }
           i--;
        }
        while(j>=0 ){
           int sum=(b[j]-'0')+c;
           if(sum==3){
            c=1;
            ans="1"+ans;
           }
           if(sum==2){
             c=1;
            ans="0"+ans;
           }
           if(sum==1){
             c=0;
            ans="1"+ans;
           }
            if(sum==0){
             c=0;
            ans="0"+ans;
           }
           j--;
        }
        if(c==1)
        ans="1"+ans;
return ans;
    }
};