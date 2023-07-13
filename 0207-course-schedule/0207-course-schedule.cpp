class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<int> indegree(numCourses,0);
        unordered_map<int, vector<int>> u;
        for(auto it:p)
        {
            u[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        int c=0;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto it=q.front();
            c++;
            q.pop();
            for(auto ne:u[it])
            {
                if(--indegree[ne]==0)
                    q.push(ne);
            }
        }
        return c==numCourses;
    }
};