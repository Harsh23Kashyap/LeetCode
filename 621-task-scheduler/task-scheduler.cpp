class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> u;
        for(auto it:tasks)
            u[it]++;
        
        priority_queue<int> pq;

        for(auto it:u)
            pq.push(it.second);

        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() or !q.empty()){
            time++;
            // cout<<time<<endl;
            while(!q.empty() and q.front().first<=time){
                auto it=q.front();
                pq.push({it.second});
                q.pop();
            }
            if(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                if(it-1>0)
                    q.push({time+n+1,it-1});
            }

            
        }

        return time;


    }
};