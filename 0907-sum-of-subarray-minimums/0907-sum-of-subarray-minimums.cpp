class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> next(n),prev(n);
        stack<int> s1,s2;
        for(int i=0;i<n;i++)
        {
            next[i]=n-i-1;
            prev[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() and arr[s1.top()]>arr[i])
            {
                next[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() and arr[s2.top()]>=arr[i])
            {
                prev[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        
        int mod=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=((long)arr[i]*(next[i]+1)*(prev[i]+1))%mod;
        }
        return sum%mod;
        
    }
};