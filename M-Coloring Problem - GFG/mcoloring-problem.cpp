// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool pos(bool graph[101][101],int j,int col,int n,int color[])
{
    for(int i=0;i<n;i++)
    {
        if(i!=j and graph[j][i]==true)
        {
            if(color[i]==col)
            return false;
        }
    }
    return true;
}
bool mColor(bool graph[101][101],int m, int n, int color[], int j)
{
    if(j==n)
    return true;
    
    for(int col=1;col<=m;col++)
    {
        if(pos(graph,j,col,n,color))
        {
            color[j]=col;
             if(mColor(graph,m,n,color,j+1))
                return true;
            color[j]=0;
        }
        
    }
    return false;
   
}
bool graphColoring(bool graph[101][101], int m, int n) 
{
    int color[n]={0};
//   for(int i=0;i<n;i++)
//   {
//       for(int j=0;j<n;j++)
//         cout<<graph[i][j]<<" ";
//         cout<<endl;
//   }
    if(mColor(graph,m,n,color,0))
    return true;
    
    return false;
    // your code here
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends