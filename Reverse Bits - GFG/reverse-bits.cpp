// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        long long ans=0;
        for(int i=0;i<32;i++)
        {
            int dig=X&1;
            ans=ans<<1;
            ans=ans|dig;
            X=X>>1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}  // } Driver Code Ends