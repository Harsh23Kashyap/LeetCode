class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            indegree[v]++;
            isPre[u][v] = true;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int course = q.front(); q.pop();
            for (int next : graph[course]) 
            {
                for (int i = 0; i < numCourses; ++i) {
                    if (isPre[i][course]) {
                        isPre[i][next] = true;
                    }
                }
                isPre[course][next] = true;
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(isPre[q[0]][q[1]]);
        }
        return ans;
    }
};
