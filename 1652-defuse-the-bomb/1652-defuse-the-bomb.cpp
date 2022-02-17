class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n=code.size();
        if(k==0)
        {
            vector<int> v(n,0);
            return v;
        }
        vector<int> v;
        if(k>0)
        {
            cout<<"runs";
            int c=1;
            int sum=0;
            int j=1;
            for(int i=1;i<=k;i++)
            {
                sum+=code[i];
                j=(j+1)%n;
            }
            v.push_back(sum);
            for(int i=1;i<code.size();i++)
            {
                cout<<j<<endl;
                sum=sum+code[j]-code[i];
                j=(j+1)%n;
                v.push_back(sum);
            }
    
        }
        if(k<0)
        {
            cout<<"no run";
            reverse(code.begin(),code.end());
            int sum=0;
            int j=1;
            for(int i=1;i<=abs(k);i++)
            {
                sum+=code[i];
                j=(j+1)%n;
            }
            v.push_back(sum);
            for(int i=1;i<code.size();i++)
            {
                cout<<sum<<endl;
                sum=sum+code[j]-code[i];
                j=(j+1)%n;
                v.push_back(sum);
            }
            reverse(v.begin(),v.end());
            return v;
        }
            return v;
    }
};



