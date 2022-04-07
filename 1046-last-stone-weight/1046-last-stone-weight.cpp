class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        for(int i:stones)
            pq.push(i);
        
        while(pq.size()>1)
        {
            int top=pq.top();
            pq.pop();
            int stop=pq.top();
            pq.pop();
            if(top!=stop)
                pq.push(top-stop);
        }
        if(pq.empty())
            return 0;
        return pq.top();
        
    }
};