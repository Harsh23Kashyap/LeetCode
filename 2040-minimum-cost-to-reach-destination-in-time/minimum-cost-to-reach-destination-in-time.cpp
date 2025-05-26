class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;

        unordered_map<int,vector<pair<int,int>>> u;
        for(auto it:edges){
            u[it[0]].push_back({it[1],it[2]});
            u[it[1]].push_back({it[0],it[2]});
        }
        int nnn=passingFees.size();
        vector<int> minCost(nnn, INT_MAX);
        vector<int> minTime(nnn, INT_MAX);


        minCost[0] = passingFees[0];
        minTime[0] = 0;
        //{cost,time,node}
        pq.push({passingFees[0],0,0});

        while(!pq.empty()){

            auto it=pq.top();
            int currcost =it[0],time =it[1],node=it[2];
            pq.pop();
            if (node == nnn - 1) return currcost;

            if (currcost > minCost[node] && time > minTime[node]) continue;

            // cout<<" At "<<node<<" "<<currcost<<endl;
            for(auto n:u[node]){
                int newnode=n.first;
                int edgetime=n.second;
                
                int nc=currcost+passingFees[newnode];
                // cout<<"For "<<newnode<<" "<<nc<<endl;
                int nt=time+edgetime;
                if(nt>maxTime)
                    continue;
                if (nc < minCost[newnode] or nt < minTime[newnode]) {
                    minCost[newnode] = nc;
                    minTime[newnode] = nt;
                
                    // cost[newnode][nt]=nc;
                    pq.push({nc,nt,newnode});
                }



            }


        }
        return -1;
        // return cost[nnn-1];
    }
};