class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int n=s.length();
        cout<<n;
        if(n<k) 
        {
            reverse(s.begin(),s.end());
            return s;
        }
        if(n<2*k)
        {
            string first=s.substr(0,k);
            reverse(first.begin(),first.end());
            string second= s.substr(k);
            return first+second;
        }
        else 
        {
            int i=0,j=k;
            for(;j<n;i+=2*k,j+=2*k)
                reverse(s.begin()+i,s.begin()+j);
            if(i<n) reverse(s.begin()+i,s.end());
        }
        
        return s;
    }
};