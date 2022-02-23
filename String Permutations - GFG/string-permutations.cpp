// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void per(string t, int i,vector<string>& ans)
    {
        if(i==t.length())
        {
            ans.push_back(t);
        }
        else
        {
            //cout<<i<<" "<<t<<endl;
            for(int j=i;j<t.length();j++)
            {
                char ch=t[i];
                t[i]=t[j];
                t[j]=ch;
                per(t, i+1,ans);
                ch=t[i];
                t[i]=t[j];
                t[j]=ch;
            }
        }
    }
    vector<string> permutation(string S)
    {
         vector<string> ans;
         per(S,0,ans);
         sort(ans.begin(),ans.end());
         return ans;
        //Your code here
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  // } Driver Code Ends