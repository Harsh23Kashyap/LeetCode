// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void sub(vector<int> arr, int i, int N, vector<int> &sum, int tot)
    {
        if(i==N)
        {
            //cout<<tot<<endl;
            sum.push_back(tot);
            return ;
        }
        
        //include 
        sub(arr,i+1,N,sum,tot+arr[i]);
        //exclude
        sub(arr,i+1,N,sum,tot);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sum;
        sub(arr,0,N,sum,0);
        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends