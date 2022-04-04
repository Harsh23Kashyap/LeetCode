class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string ans="";
        vector<int> factorial(10,1);
        for(int i=2;i<=9;i++)
        {
            factorial[i]=factorial[i-1]*i;
        }
        //cout<<"runs"<<endl;
        vector<int> digits(n,0);
        for(int i=1;i<=n;i++)
            digits[i-1]=i;
        //cout<<"runs"<<endl;
        while(n>0)
        {
            int index=k/factorial[n-1];
            if(k%factorial[n-1]==0)
                index--;
            
            ans+=to_string(digits[index]);
            k-=(factorial[n-1]*index);
            n--;
            digits.erase(digits.begin()+index);
            
        }
        return ans ;
    }
    
};