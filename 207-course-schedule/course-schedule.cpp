class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> u;
        vector<int> indegree(n,0);
        for(auto it:prerequisites){
            u[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        int c=0;
        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                c++;
            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto nn:u[it]){
                indegree[nn]--;
                if(indegree[nn]==0){
                    c++;
                q.push(nn);
                }
            }
        }

        return c==n;


    }
};