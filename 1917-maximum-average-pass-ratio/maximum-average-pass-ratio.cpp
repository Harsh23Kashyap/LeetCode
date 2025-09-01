class Solution {
public:
typedef pair<double,pair<int,int>> pp;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pp> pq;
        int tot=classes.size();
        double total=0;
        for(auto it:classes){
            double avg=it[0]*1.0/it[1];
            double nexavg=(it[0]+1)*1.0/(it[1]+1);
            // cout<<nexavg-avg<<endl;
            pq.push({nexavg-avg,{it[0],it[1]}});
            // total+=avg;
        }

        while(extraStudents>0){
            auto it=pq.top();
            // total-=it.first;
            // cout<<it.first<<" ->"<<it.second.first<<"/"<<it.second.second<<endl;
            pq.pop();
            double avg=(it.second.first+1)*1.0/(it.second.second+1.0);
            double nextavg=(it.second.first+2)*1.0/(it.second.second+2.0);
            pq.push({nextavg-avg,{it.second.first+1,it.second.second+1}});
            // cout<<"New avg "<<avg<<endl;
            // total+=avg;
            extraStudents--;
        }
        while(!pq.empty()){
            auto it=pq.top();
            total+=(it.second.first*1.0/it.second.second);
            pq.pop();
        }
        return total/tot;
    }
};