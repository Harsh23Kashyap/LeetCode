// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool cmp(Item a,Item b)
    {
        double pwa=a.value*1.0/a.weight;
        double pwb=b.value*1.0/b.weight;
        return pwa>=pwb;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                ans+=arr[i].value;
                W-=arr[i].weight;
                
            }
            else
            {
                ans+=(arr[i].value*1.0/arr[i].weight)*W*1.0;
                break;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends