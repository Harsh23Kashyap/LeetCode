class Solution {
public:
    int m=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i:nums)
            pq.push(i);
        
        while(k--)
        {
            int t=pq.top();
            pq.pop();
            pq.push(t+1);
        }
        long long ans=1;
        while(!pq.empty())
        {
            ans=(ans*1ll*pq.top()+m)%m;
            pq.pop();
        }
        return ans%m;
        
    }
};