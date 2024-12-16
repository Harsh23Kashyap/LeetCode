class Solution {
typedef pair<int,int> pp;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});
        
        while(k--)
        {
            auto [i,val]=pq.top();
            pq.pop();
            pq.push({i*multiplier,val});
        }
        
        while(!pq.empty()){
            auto [i,val]=pq.top();
            pq.pop();
            nums[val]=i;
        }
        return nums;
    }
};