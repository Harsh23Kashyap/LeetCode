class TaskManager {
public:
unordered_map<int,int> taskId_update;
unordered_set<int> vis;
priority_queue<pair<int,int>> pq;
unordered_map<int, int> all;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            all[it[1]]=it[0];
            pq.push({it[2],it[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
         all[taskId]=userId ;
         if(taskId_update.find(taskId)!=taskId_update.end())
         taskId_update[taskId]=priority;
         pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        // cout<<taskId<<" - "<<newPriority<<endl;
        taskId_update[taskId]=newPriority;
        pq.push({newPriority,taskId});

    }
    
    void rmv(int taskId) {
        taskId_update[taskId]=-1;
    }
    
    int execTop() {

        while(!pq.empty()){
            auto it=pq.top();
            cout<<it.first<<" "<<it.second<<endl;
            pq.pop();
            // if(vis.find(it.second)!=vis.end()){
            //     vis.erase(it.second);
            //     continue;
            // }
            if(taskId_update.find(it.second)!=taskId_update.end()){
                if(taskId_update[it.second]==-1){
                    continue;
                }
                else if(taskId_update[it.second]!=it.first){
                    cout<<"to be removed"<<endl;
                    pq.push({taskId_update[it.second],it.second});
                    continue;
                }
            }
            cout<<all[it.second]<<endl;
            taskId_update[it.second]=-1;
            return all[it.second];
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */