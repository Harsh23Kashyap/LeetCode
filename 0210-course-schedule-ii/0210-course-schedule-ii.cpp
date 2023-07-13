class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
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
        vector<int> order;
        while(!q.empty())
        {
            auto it=q.front();
            c++;
            order.push_back(it);
            q.pop();
            for(auto ne:u[it])
            {
                if(--indegree[ne]==0)
                    q.push(ne);
            }
        }
        if(c==numCourses)
            return order;
        return {};
    }
};