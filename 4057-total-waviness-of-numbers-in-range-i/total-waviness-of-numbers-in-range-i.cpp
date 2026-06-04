class Solution {
public:
    int pass(int num){

        int c=0;

        string str=to_string(num);
        for(int i=1;i<str.size()-1;i++){
            if(str[i]>str[i-1] and str[i]>str[i+1])
                c++;
            if(str[i]<str[i-1] and str[i]<str[i+1])
                c++;
            
        }
        return c;
    }
    int totalWaviness(int num1, int num2) {
        
        int c=0;
        for(int i=num1;i<=num2;i++){
             int tot=pass(i);
            //  cout<<i<<" "<<tot<<endl;
             c+=tot;
        }
        return c;
    }
};