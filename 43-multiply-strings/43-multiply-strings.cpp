class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int n=num1.size(),m=num2.size();
        vector<int> sum(m+n,0);
        //cout<<sum.size()<<endl;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int pos=(n-i-1 + m-j-1);
                //cout<<pos<<endl;
                sum[pos]+=((num1[i]-'0')*(num2[j]-'0'));
                sum[pos+1]+=sum[pos]/10;
                sum[pos]=sum[pos]%10;
            }
        }
        //cout<<"runs"<<endl;
        string ans="";
        for(int i=0;i<sum.size();i++)
            ans=to_string(sum[i])+ans;
        
        int i=0;
        while(i<ans.size() and ans[i++]=='0');
        
        return ans.substr(i-1);
        
    }
};