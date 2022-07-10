class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        int arr[n+1];
        arr[0]=0;
        arr[1]=0;
        //arr[2]=0;
        
        for (int i=2;i<n+1;i++)
        {
            arr[i]=min(cost[i-1]+arr[i-1],cost[i-2]+arr[i-2]);
            cout<<"For step "<<i<<" cost - "<<arr[i]<<endl;
        }
        return arr[n];
    }
};