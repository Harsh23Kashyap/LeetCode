class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& deps) {
    vector<int> ans;
         vector<int> indegree(n,0);
         unordered_map<int,vector<int>> u;

         for(auto it:deps){
            u[it[1]].push_back(it[0]);
            indegree[it[0]]++;

         }

         queue<int> q;
         for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
             ans.push_back(i);
                q.push(i);
            }
         }

         while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto ne:u[it]){
                if(--indegree[ne]==0){
                q.push(ne);
                ans.push_back(ne);
                }
            }
         }
         if(ans.size()==n)
            return true;
            return false;


    }
};