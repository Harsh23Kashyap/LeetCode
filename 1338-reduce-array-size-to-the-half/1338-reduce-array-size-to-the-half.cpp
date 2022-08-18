class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        
        unordered_map<int,int> u;
        for(int i:arr)
            u[i]++;
        
        priority_queue<int> pq;
        for(auto it:u)
            pq.push(it.second);
        
        int c=0;
        int sum=0;
        while(sum<(n/2))
        {
            c++;
            sum+=pq.top();
            pq.pop();
            
        }
        return c;
        
        
    }
};