// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> u;
        int csum=0;
        u[0]=-1;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            csum+=A[i];
            if(u.find(csum-0)!=u.end())
                maxi=max(maxi,i-u[csum]);
            else
                u[csum]=i;
        }
        return maxi;
        // Your code here
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends