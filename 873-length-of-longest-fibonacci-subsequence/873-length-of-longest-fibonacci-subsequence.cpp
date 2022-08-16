class Solution {
public:
//     int lenLongestFibSubseq(vector<int>& arr) 
//     {
//         unordered_set<int> s(arr.begin(),arr.end());
//         int maxi=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             for(int j=i+1;j<arr.size();j++)
//             {
//                 int x=arr[i],y=arr[j];
//                 int curr=2;
//                 while(s.find(x+y)!=s.end())
//                 {
//                     curr++;
//                     int temp=x+y;
//                     x=y,y=temp;
//                 }
//                 maxi=max(curr,maxi);
//             }
//         }
//         return maxi>=3?maxi:0;
        
//     }
    int lenLongestFibSubseq(vector<int>& A) 
    {
        int n=A.size();
       unordered_map<int, int> m;
    int N = n, res = 0;
 
    // Initialize dp table
    int dp[N][N];
 
    // Iterate till N
    for (int j = 0; j < N; ++j) {
        m[A[j]] = j;
        for (int i = 0; i < j; ++i) {
            // Check if the current integer
            // forms a fibonacci sequence
            int k = m.find(A[j] - A[i]) == m.end()
                        ? -1
                        : m[A[j] - A[i]];
 
            // Update the dp table
            dp[i][j] = (A[j] - A[i] < A[i] && k >= 0)
                           ? dp[k][i] + 1
                           : 2;
            res = max(res, dp[i][j]);
        }
    }
 
    // Return the answer
    return res > 2 ? res : 0;
    }
};