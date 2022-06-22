class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for(int i:nums)
            pq.push(i);
        
        
        int i=1;
        while(i++<k)
            pq.pop();
        return pq.top();
    }
};