// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
    // function to find totient of n
    int ETF(long long N)
    {
        float ans=N;
        for(int i=2;i*i<=N;i++)
        {
            if(N%i==0)
            {
                while(N%i==0)
                N/=i;
                
                ans=ans*(1.0-(1.0/float(i)));
            }
                
        }
        
        if(N>1)
        {
            ans*=(1.0-(1.0/float(N)));
        }
        return (int)ans;
       
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends