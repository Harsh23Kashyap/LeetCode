class Solution {
public:
    int climbStairs(int n) {
        int arr[n+2];
        arr[0]=-1;
        arr[1]=1;
        arr[2]=2;
        for(int i=3;i<n+1;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};