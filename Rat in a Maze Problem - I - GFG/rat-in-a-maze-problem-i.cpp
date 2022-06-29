// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void solve(vector<string> &ans, string s, vector<vector<int>> &m, int n, int i, int j)
    {
       // cout<<i<<" , "<<j<<endl;
         
        
        if(i>=n or j>=n or i<0 or j<0 or m[i][j]==0 or m[i][j]==0)
            return;
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            return;
        }
       m[i][j]=0;
        //UP
         solve(ans,s+'U',m,n,i-1,j);
        //DOWN
        solve(ans,s+'D',m,n,i+1,j);
         //LEFT
         solve(ans,s+'L',m,n,i,j-1);
        //RIGHT
        solve(ans,s+'R',m,n,i,j+1);
       
         m[i][j]=1;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        // Your code goes here
        if(m[0][0]==0 or m[n-1][n-1]==0)
        return {"-1"};
        vector<string> ans;
        string s="";
        solve(ans,s,m,n,0,0);
        // if(ans.size()==1)
        // return -1;
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends