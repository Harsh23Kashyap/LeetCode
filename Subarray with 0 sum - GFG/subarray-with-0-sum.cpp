// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        vector<int> prefix (n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+arr[i];
        
        unordered_map<int,int> m;
        for(int i:prefix)
        {
            if(m.find(i)!=m.end())
                return true;
            else
                m[i]=1;
        }
        return m.find(0)!=m.end();
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends