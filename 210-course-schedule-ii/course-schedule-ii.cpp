class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> u;
        vector<int> indegree(numCourses,0);
        for(auto it:p){
            u[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        int c=0;
        queue<int> q;
        vector<int> courseee;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                c++;
            }
        }

        while(!q.empty()){
            auto it=q.front();
            courseee.push_back(it);
            q.pop();
            for(auto nn:u[it]){
                indegree[nn]--;
                if(indegree[nn]==0){
                    c++;
                q.push(nn);
                }
            }
        }

        if(courseee.size()==numCourses){
            return courseee;
        }
        return {};

    }
};