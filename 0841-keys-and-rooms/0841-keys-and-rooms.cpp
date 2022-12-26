class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        queue<int> q;
        q.push(0);
        unordered_set<int> vis;
        
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            vis.insert(top);
            for(int i=0;i<rooms[top].size();i++)
            {
                if(vis.find(rooms[top][i])==vis.end())
                {
                    q.push(rooms[top][i]);
                    vis.insert(rooms[top][i]);
                }
            }
        }
        
        return vis.size()==rooms.size();
        
        
    }
};