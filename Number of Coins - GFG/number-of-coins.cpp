// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1,0);
	    for(int i=1;i<V+1;i++)
	    {
	        dp[i]=INT_MAX;
	        for(int j=0;j<M;j++)
	        {
	            if(i-coins[j]>=0)
	            {
	                int k=dp[i-coins[j]];
	                if(k!=INT_MAX)
	                    dp[i]=min(k+1,dp[i]);
	            }
	        }
	    }
	    if(dp[V]!=INT_MAX)
	    return dp[V];
	    return -1;
	    
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends