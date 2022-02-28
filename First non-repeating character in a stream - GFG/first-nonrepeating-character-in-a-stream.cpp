// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    unordered_map <char,int> u;
		    string ans="";
		    queue<char> q;
		    
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        u[A[i]]++;
		        while(!q.empty() and u[q.front()]>1)
		            q.pop();
		        
		        if(q.empty())
		            ans+='#';
		        else
		        {
		            ans+=q.front();
		            //cout<<q.front();
		        }
		        
		    }
		    return ans;
		    // Code here
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends