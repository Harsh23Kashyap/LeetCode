// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void recursive(vector<string>& ans,string t, int i)
	    {
	        if(i==t.length())
	        {
	            ans.push_back(t);
	            return;
	        }
	        for(int j=i;j<t.length();j++)
	        {
	            swap(t[i],t[j]);
	            recursive(ans,t,i+1);
	            swap(t[i],t[j]);
	            
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    
		    recursive(ans,S,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends