class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        
        while(k--)
        {
            int t=pq.top();
            pq.pop();
            // cout<<t<<" "<<floor(sqrt(t))<<endl;
            pq.push(floor(sqrt(t)));
        }
        
        long long sz=0;
        while(!pq.empty())
        {
            // cout<<pq.top()<<endl;
            sz+=pq.top();
            pq.pop();
        }
        
        return sz;
        
    }
};