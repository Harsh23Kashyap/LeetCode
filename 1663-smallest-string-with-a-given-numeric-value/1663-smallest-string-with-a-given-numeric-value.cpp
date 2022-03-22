class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string str="";
        if(n==1)
            return str+char(96+k);
        
        int c=0;
        while(k-26>=n-c)
        {
            c++;
            str+='z';
            k-=26;
        }
        cout<<str.length()<<endl;
        cout<<k<<endl;
        cout<<n-c<<endl;
        for(int i=0;i<n-c-1;i++)
        {
            str+='a';
            k-=1;
        }
        cout<<k<<endl;
        if(k>0)
            str+=char(96+k);
        
        sort(str.begin(),str.end());
        return str;
        
    }
};